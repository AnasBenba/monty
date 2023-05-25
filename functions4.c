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
		fprintf(stderr ,"L%i: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 || (*stack)->n <= 127)
	{
		printf("%c\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr ,"L%i: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
}
