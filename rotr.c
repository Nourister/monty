#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current opcode
 * Return: 0(success)
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *new_last = NULL;

	if (current == NULL || current->next == NULL)
		return; 

	while (current->next != NULL)
	{
		new_last = current;
		current = current->next;
	}

	new_last->next = NULL;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = current;
	(void)line_number;
}

