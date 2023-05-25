#include "monty.h"

void pchar(stack_t **stack, unsigned int line_number)
{
	int i;

	if (*stack == NULL)
	{
		fprintf(stderr ,"L%i: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = (*stack)->n;

	if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
	{
		printf("%c\n", i);
	}
	else
	{
		fprintf(stderr ,"L%i: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
}
