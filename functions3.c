#include "monty.h"

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int i = 0;

	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	i = (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->n -= i;
}

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int i = 0;

	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	i = (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->n /= i;
}

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int i = 0;

	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%i: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	i = (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->n *= i;
}
