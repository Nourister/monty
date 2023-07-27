#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * process_file - Read and process the Monty byte code file.
 * @filename: Name of the Monty byte code file to be processed.
 *
 * This function reads and interprets Monty byte code instructions from the
 * specified file @filename. It executes the corresponding operations,
 * maintaining a stack of integers. It uses a doubly-linked list for the stack.
 *
 * If any errors occur during file processing, the function terminates the
 * program with EXIT_FAILURE.
 */
void process_file(const char *filename)
{
	char line[1024];
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode;
	char *argument;
	int n;

	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;

		/* Remove trailing newline character */
		line[strcspn(line, "\n")] = '\0';

		opcode = strtok(line, " ");
		argument = strtok(NULL, " ");

		if (opcode == NULL)
			continue; /* Empty line, skip to the next line */

		if (strcmp(opcode, "push") == 0)
		{
			if (argument == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(file);
				exit(EXIT_FAILURE);
			}

			n = atoi(argument);
			if (n == 0 && strcmp(argument, "0") != 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(file);
				exit(EXIT_FAILURE);
			}

			add_dnodeint(&stack, n);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		/* Add other opcode cases here, as needed */
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
}

