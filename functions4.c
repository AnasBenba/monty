#include "monty.h"

/**
 * pchar - Prints the ASCII character at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int i;

	if (*stack == NULL)
	{
		fprintf(stderr ,"L%i: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = (*stack)->n;

	if (i >= 0 || i <= 127)
	{
		printf("%c\n", i);
	}
	else
	{
		fprintf(stderr ,"L%i: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
}
