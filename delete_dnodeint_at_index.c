#include "monty.h"

/*
 * delete_dnodeint_at_index - Deletes the node at index 'index' of a stack_t linked list.
 * @stack: Double pointer to the head of the stack.
 * @index: The index of the node that should be deleted. Index starts at 0.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(stack_t **stack, unsigned int index)
{
	stack_t *current;
	unsigned int i = 0;

	if (*stack == NULL)
		return (-1);

	current = *stack;
	while (current != NULL)
	{
		if (i == index)
		{
			if (current->next != NULL)
				current->next->prev = current->prev;

			if (current->prev != NULL)
				current->prev->next = current->next;
			else
				*stack = current->next;

			free(current);
			return (1);
		}

		i++;
		current = current->next;
	}

	return (-1);
}
