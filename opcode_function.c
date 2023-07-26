#include "monty.h"
/**
 * get_opcode_function - Searches for an opcode function.
 * @opcode: The opcode to search for.
 * Return: The function pointer to the matched opcode function, or NULL if no
 * match is found.
 */
opcode_f get_opcode_function(char *opcode)
{
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}
    };

    int i = 0;
    while (instructions[i].opcode != NULL) {
        if (strcmp(opcode, instructions[i].opcode) == 0)
            return instructions[i].f;
        i++;
    }
    return NULL;
}
