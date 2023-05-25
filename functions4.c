#include "monty.h"

/**
 * pchar - Prints the ASCII character at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%i: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - Prints the string contained in the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;

	if (*stack == NULL)
	{
		printf("\n");
	}
	else
	{
		ptr = *stack;
		while (ptr)
		{
			if (ptr->n == 0)
			{
				break;
			}
			if (ptr->n < 0 || ptr->n > 127)
			{
				break;
			}
			printf("%c", ptr->n);
			ptr = ptr->next;
		}
		printf("\n");
	}
}
