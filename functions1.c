#include "monty.h"

/**
 * check_integer - Check if a string represents an integer
 * @str: The string to be checked
 * Return: 1 if the string represents an integer, 0 otherwise
 */
int check_integer(const char *str)
{
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
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

/**
 * push - Push an element onto the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: The line number where the instruction is encountered
 */
void push(stack_t **stack, unsigned int line_number)
{
	int val;
	stack_t *new = malloc(sizeof(stack_t));

	if (var.args[1] == NULL || !check_integer(var.args[1]))
	{
		free(var.args);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (new == NULL)
	{
		free(var.args);
		fprintf(stderr, "Error: malloc failed\n");
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

/**
 * pall - Print all the elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: The line number where the instruction is encountered
 */
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

/**
 * check_line - Check and execute instructions based on the input line
 * @line: The input line to be checked
 * @stack: Double pointer to the top of the stack
 */
void check_line(char *line, stack_t **stack)
{
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};
	int i = 0;

	var.args[0] = strtok(line, " \n\t");
	var.args[1] = strtok(NULL, " \n\t");

	if (var.args[0] != NULL)
	{
		while (instruction[i].opcode != NULL)
		{
			if (strcmp(instruction[i].opcode, var.args[0]) == 0)
			{
				instruction[i].f(stack, var.line);
				return;
			}
			i++;
		}
		fprintf(stderr, "L%d: unknown instruction %s\n", var.line, var.args[0]);
		free(var.args);
		exit(EXIT_FAILURE);
	}
}
