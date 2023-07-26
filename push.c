#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/* Implementation of push opcode */
void push(stack_t **stack, int n, unsigned int line_number)
{
    /* Create a new node for the integer */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;

    /* If the stack is empty, set the new node as the top of the stack */
    if (*stack == NULL)
    {
        new_node->next = NULL;
        *stack = new_node;
    }
    else
    {
        /* Add the new node to the top of the stack */
        new_node->next = *stack;
        (*stack)->prev = new_node;
        *stack = new_node;
    }
}
