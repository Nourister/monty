#include "monty.h"

/*
 * push - Executes the 'push' opcode.
 * @stack: Double pointer to the stack.
 * @line_number: The line number where the 'push' opcode is.
 * Return: 0(success)
 */
void push(stack_t **stack, unsigned int line_number)
{
    int n;

    char* data = strtok(NULL, "\n\t\r "); /* get the data after opcode */
    
    if (data == NULL || check_if_number(data) == 0)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(data);
    add_dnodeint(stack, n);
}
