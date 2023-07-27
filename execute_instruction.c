#include "monty.h"
/*
 * execute_instruction - Executes the correct function for each opcode.
 * @stack: Double pointer to the stack.
 * @line_number: The line number where the opcode is.
 * Return: 0(success)
 */
void execute_instruction(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t op_func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"stack_div", stack_div},
		 {"mul", mul},
		{NULL, NULL}
	};

	while (op_func[i].opcode != NULL)
	{
		if (strcmp(global_data, op_func[i].opcode) == 0)
		{
			op_func[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, global_data);
	exit(EXIT_FAILURE);
}
