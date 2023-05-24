#include "monty.h"

/**
 * free_stack - Free all nodes in a stack
 * @stack: Double pointer to the top of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		*stack = (*stack)->next;
		free(ptr);
		ptr = *stack;
	}
}

/**
 * pint - Print the value at the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: The line number where the instruction is encountered
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free((*stack)->prev);
}
