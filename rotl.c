#include "monty.h"
#include <ctype.h>

/**
 * rotl - rotates the stack to the top.
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current opcode
 * Return: 0(success)
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	
	if (current == NULL || current->next == NULL)
		return;

	while (current->next != NULL)
		current = current->next;

	current->next = *stack;
	(*stack)->prev = current;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	current->next->next = NULL;
	(void)line_number;
}
