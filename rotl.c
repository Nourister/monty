#include "monty.h"

/* Function to rotate the stack to the top */
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

