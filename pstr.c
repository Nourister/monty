#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current opcode
 * Return: 0(success)
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL && current->n != 0 && current->n >= 0
	&& current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
	(void)line_number;
}

