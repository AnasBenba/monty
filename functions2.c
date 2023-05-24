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
