#include "monty.h"

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: double pointer to the head of the stack.
 * @line_number: line number in the file.
 *
 * Return: void.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
