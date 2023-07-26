#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern char *global_data;

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*void push(stack_t **stack, unsigned int line_number);*/
/*void pall(stack_t **stack, unsigned int line_number);*/
void push(stack_t **stack, unsigned int line_number, const char* argument);
void pall(stack_t **stack, unsigned int line_number, const char* argument);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
int check_if_number(char *str);
void add_dnodeint(stack_t **stack, int n);
int delete_dnodeint_at_index(stack_t **stack, unsigned int index);
void execute_instruction(stack_t **stack, unsigned int line_number);


#endif /* MONTY_H */
