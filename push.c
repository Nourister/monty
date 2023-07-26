#include "monty.h"

/**
 * push - Push an element to the stack.
 * @stack: double pointer to the head of the stack.
 * @line_number: line number in the file.
 *
 * Return: void.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *new;

	for (i = 0; global_data[i]; i++)
	{
		if (isdigit(global_data[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(global_data);
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
