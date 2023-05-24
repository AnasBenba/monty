#include "monty.h"

/**
 * nop - Does nothing
 * @stack: Pointer to the pointer of the stack's top element
 * @line_number: Line number where the nop function is called
 *
 * Description: This function does nothing and is used as a placeholder.
 * It takes in the stack pointer and line number
 * as arguments, but doesn't perform any operation.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - Subtracts the top two elements of the stack
 * @stack: Pointer to the pointer of the stack's top element
 * @line_number: Line number where the sub function is called
 *
 * Description: This function subtracts the top two elements in the stack
 * and replaces them with their difference.
 * If the stack has fewer than 2 elements,
 * it prints an error message and exits the program.
 */
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

/**
 * _div - Divides the second top element of the stack by the top element
 * @stack: Pointer to the pointer of the stack's top element
 * @line_number: Line number where the _div function is called
 *
 * Description: This function divides the second top element of the stack
 * by the top element and replaces them with the quotient. If the stack has
 * fewer than 2 elements, it prints an error message and exits the program.
 * If the top element is 0, it prints an error message for division by zero
 * and exits the program.
 */
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

/**
 * mul - Multiplies the top two elements of the stack
 * @stack: Pointer to the pointer of the stack's top element
 * @line_number: Line number where the mul function is called
 *
 * Description: This function multiplies the top two elements in the stack
 * and replaces them with their product.
 * If the stack has fewer than 2 elements,
 * it prints an error message and exits the program.
 */
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

/**
 * mod - Computes the remainder of dividing
 * the second top element by the top element
 * @stack: Pointer to the pointer of the stack's top element
 * @line_number: Line number where the mod function is called
 *
 * Description: This function computes the remainder
 * of dividing the second top element
 * of the stack by the top element, and replaces
 * them with the result. If the stack has
 * fewer than 2 elements, it prints an error
 * message and exits the program. If the top
 * element is 0, it prints an error message for
 * division by zero and exits the program.
 */
void mod(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
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
	(*stack)->n %= i;
}
