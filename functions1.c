#include "monty.h"

int check_integer(const char* str)
{
	int i = 0;

	if (str[i] == '-')
	{
		i++;
	}
	for ( ; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
		{
			return (0);
		}
	}
	return (1);
}

void push(stack_t **stack, unsigned int line_number)
{
	int val;
	stack_t *new = malloc(sizeof(stack_t));

	printf("%s/n", var.args[1]);

	if (var.args[1] == NULL || !check_integer(var.args[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (new == NULL)
	{
		fprintf(stderr ,"Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	val = atoi(var.args[1]);
	new->n = val;
	new->prev = NULL;
	new->next = NULL;
	if (*stack == NULL)
	{
		*stack = new;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}

void pall(stack_t **stack, unsigned int line_number)
{
	unsigned int i = line_number;
	stack_t *ptr = *stack;
	while (ptr)
	{
		printf("%i\n", ptr->n);
		ptr = ptr->next;
		i++;
	}
}

void check_line(char *line, stack_t **stack)
{
        instruction_t instruction[] = {
                {"push", push},
                {"pall", pall},
                {NULL, NULL}
        };
        int i = 0;

        var.args[0] = strtok(line, " ");
        var.args[1] = strtok(NULL, " ");

        if (var.args[0] != NULL)
        {
                if (instruction[i].opcode == NULL)
		{
                        fprintf(stderr, "L%d: unknown instruction %s\n", var.line, var.args[0]);
                        exit(EXIT_FAILURE);
                }
                while (instruction[i].opcode != NULL)
                {
                        if (strcmp(instruction[i].opcode, var.args[0]) == 0)
                        {
                                instruction[i].f(stack, var.line);
                                return;
                        }
                        i++;
                }
        }
}
