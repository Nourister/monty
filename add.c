#include "monty.h"

/*
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: The line number where the 'add' opcode is.
 * Return: None (void).
 */

void add(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = tmp;
}
