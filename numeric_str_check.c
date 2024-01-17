#include "monty.h"

/**
 * isNumericString - function checks if a given string
 * represents a numerical value.
 * This function checks if the given string represents a numerical value,
 * considering negative numbers as well.
 *
 * @s: The input string to be checked.
 *
 * Return: Returns 1 if the string represents
 * a numerical value, and 0 otherwise.
 *
 */
int isNumericString(char *s)
{
	/* Check for negative sign and move to the next character */
	if (*s == '-')
	{
		s++;

		/* Check if the next character is a digit */
		if (*s < '0' || *s > '9')
		{
			return (0);
		}

		/* Move to the next character */
		s++;
	}

	/* Check the remaining characters for digits */
	while (*s != 0)
	{
		if (*s < '0' || *s++ > '9')
		{
			return (0);
		}
	}

	/* The string represents a numerical value */
	return (1);
}
