#include "monty.h"

/**
 * check_if_number - Checks if a string can be converted to a number.
 * @str: String to be checked.
 *
 * Description: This function checks if each character in the string 'str'
 * is a decimal digit, indicating that 'str' can be converted to an integer.
 * Return: 1 if 'str' can be converted to an integer, 0 otherwise.
 */

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
