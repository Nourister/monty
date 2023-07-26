#include "monty.h"

int check_if_number(char *str)
{
    if (str == NULL)
        return (0);

    if (*str == '-' || *str == '+')
        str++;

    while (*str)
    {
        if (isdigit(*str) == 0)
            return (0);
        str++;
    }

    return (1);
}
