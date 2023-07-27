#include "monty.h"

/* Function to rotate the stack to the bottom */
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

