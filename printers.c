#include "monty.h"

/**
 * printChar - function prints the character at the upper of the stack.
 * This function prints the character at the upper of the stack, and
 * exits with an error message if the stack is empty
 * or the value is out of range.
 *
 * @upper: A pointer to the upper of the stack.
 *
 * Users can use this function to print the character at the upper of the stack
 */
void printChar(stack_t **upper)
{
	stack_t *ptr = *upper;

	/*
	 * Check if the stack is empty.
	 */
	if (ptr == NULL)
	{
		wrapExit(EXIT_FAILURE, "can't pchar, stack empty", *upper);
	}

	/*
	 * Check if the value is out of the valid character range.
	 */
	if (ptr->n > 127 || ptr->n < 0)
	{
		wrapExit(EXIT_FAILURE, "can't pchar, value out of range", *upper);
	}

	/*
	 * Print the character.
	 */
	printf("%c\n", (char)ptr->n);
}

/**
 * printString - function prints the string represented
 * by ASCII values in the stack.
 * This function prints the string represented by ASCII values in the stack,
 * starting from the upper of the stack and moving towards the bottom,
 * and stops when encountering a non-printable or out-of-range character.
 *
 * @upper: A pointer to the upper of the stack.
 *
 * Users can use this function to print the string
 * represented by ASCII values in the stack.
 */
void printString(stack_t **upper)
{
	stack_t *ptr = *upper;

	/*
	 * Iterate through the stack and print characters until a non-printable
	 * or out-of-range character is encountered.
	 */
	while (ptr != NULL && ptr->n <= 127 && ptr->n > 0)
	{
		printf("%c", (char)ptr->n);
		ptr = ptr->prev;
	}

	/*
	 * Print a newline character after printing the string.
	 */
	printf("\n");
}

/**
 * printAll - function prints all elements in the stack.
 * This function prints all elements in the stack, starting from the upper
 * and moving towards the bottom, along with a newline after each element.
 *
 * @upper: A pointer to the upper of the stack.
 *
 * Users can use this function to print all elements in the stack.
 */

void printAll(stack_t **upper)
{
	stack_t *ptr = *upper;

	/*
	 * Iterate through the stack and print each element along with a newline.
	 */
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->prev;
	}
}

/**
 * printTopInt - function prints the value
 * at the upper of the stack as an integer.
 * This function prints the value at the upper of the stack and
 * exits with an error message if the stack is empty.
 *
 * @upper: A pointer to the upper of the stack.
 *
 * Users can use this function to print the value at the upper of the stack.
 */
void printTopInt(stack_t **upper)
{
	/*
	 * Check if the stack is empty.
	 * If so, exit with an error message.
	 */
	if (*upper == NULL)
	{
		wrapExit(EXIT_FAILURE, "can't pint, stack empty", *upper);
	}

	/*
	 * Print the value at the upper of the stack.
	 */
	printf("%d\n", (*upper)->n);
}
