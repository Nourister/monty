#include "monty.h"

/*
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: The line number where the 'pop' opcode is.
 * Return: 0(success)
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_at_index(stack, 0);
}
