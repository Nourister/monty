#include "monty.h"

/**
 * mul - Multiplies the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number.
 * Return: 0(success)
 */

void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
