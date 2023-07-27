#include "monty.h"

/**
 * sub - Function to subtract the top element from the second top element.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the Monty file where the instruction appears.
 *
 * Return: None.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack is too short to perform subtraction */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Subtract the top element from the second top element */
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

