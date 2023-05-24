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

/**
 * pop - Removes the top element from the stack
 * @stack: Pointer to the pointer of the stack's top element
 * @line_number: Line number where the pop function is called
 *
 * Description: This function removes the top element from the stack.
 * If the stack is empty, it prints an error message and exits the program.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Pointer to the pointer of the stack's top element
 * @line_number: Line number where the swap function is called
 *
 * Description: This function swaps the positions
 * of the top two elements in the stack.
 * If the stack has fewer than 2 elements,
 * it prints an error message and exits the program.
 */
void swap(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = (*stack)->next;
	i = ptr->n;
	ptr->n = (*stack)->n;
	(*stack)->n = i;
}

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the pointer of the stack's top element
 * @line_number: Line number where the add function is called
 *
 * Description: This function adds the top two elements in the stack
 * and replaces them with their sum. If the stack has fewer than 2 elements,
 * it prints an error message and exits the program.
 */
void add(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	i = (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->n += i;
}
