#include "monty.h"

/**
 * sub - Function to subtract the top element from the second top element.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the Monty file where the instruction appears.
 *
 * Return: None.
 */

void sub(stack_t **stack, unsigned int line_number)
{
    int tmp;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    tmp = ((*stack)->next->n) - ((*stack)->n);
    pop(stack, line_number);
    (*stack)->n = tmp;
}
