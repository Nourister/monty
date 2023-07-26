#include "monty.h"

/*
 * add_dnodeint - Add a new node at the beginning of a stack_t list.
 * @stack: Double pointer to the head of the stack.
 * @n: The integer data for the new node.
 * Return: The address of the new element, or NULL if it failed.
 */

void add_dnodeint(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
