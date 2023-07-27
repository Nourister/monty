#include "monty.h"

/**
 * mod - Computes the remainder of the division of the second top element
 *       of the stack by the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number.
 * Return: 0(success)
 */

void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

