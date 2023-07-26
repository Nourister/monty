#define _GNU_SOURCE
#include "monty.h"

char *global_data = NULL;

/*
 * main - Entry point of our program.
 * @argc: The number of command-line arguments.
 * @argv: The command-line arguments.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	int read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		global_data = strtok(line, "\n\t\r ");
		if (global_data[0] == '#' || global_data == NULL) /* skip comments */
			continue;
		else
			execute_instruction(&stack, line_number);
	}

	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
}
