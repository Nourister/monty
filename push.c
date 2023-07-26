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
	int n;

	char *data = strtok(NULL, "\n\t\r ");

	if (data == NULL || check_if_number(data) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(data);
	add_dnodeint(stack, n);
}
