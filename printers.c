#include "monty.h"

/**
 * printChar - function prints the ASCII character corresponding
 * to the top element of a custom stack.
 * This function prints the ASCII character represented by
 * the top element of the
 * custom stack.
 * If the stack is empty or the value is out of the valid ASCII range,
 * it prints an error message and exits with EXIT_FAILURE.
 *
 * @custom_stack: A pointer to a pointer to the custom stack.
 * @LineNumber: The line number where the pchar operation is performed.
 */
void printChar(stack_t **custom_stack, unsigned int LineNumber)
{
	int ascii_value;

	/* Check if the stack is empty */
	if (*custom_stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", LineNumber);
		exit(EXIT_FAILURE);
	}

	/* Retrieve the value from the top element of the stack */
	ascii_value = (*custom_stack)->n;

	/* Check if the value is within the valid ASCII range */
	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", LineNumber);
		exit(EXIT_FAILURE);
	}

	/* Print the corresponding ASCII character */
	printf("%c\n", ascii_value);
}

/**
 * printString - function prints the string representation
 * of the elements in a custom stack.
 * This function prints the string representation
 * of the elements in the custom stack
 * until it reaches a non-printable character, a zero, or the end of the stack.
 *
 * @custom_stack: A pointer to a pointer to the custom stack.
 * @LineNumber: The line number where the pstr operation is performed.
 */
void printString(stack_t **custom_stack, unsigned int LineNumber)
{
	stack_t *now = *custom_stack;
	(void)LineNumber;

	/* Traverse the stack and print characters until */
	/* a non-printable character or zero is encountered */
	while (now && now->n > 0 && now->n <= 127)
	{
		printf("%c", now->n);
		now = now->next;
	}

	/* Print a newline character after printing the string */
	printf("\n");
}

/**
 * printTopInt - function prints the top element of a
 * custom stack as an integer.
 * This function prints the value of the top element of the custom stack.
 * If the stack is empty, it prints an error
 * message and exits with EXIT_FAILURE.
 *
 * @custom_stack: A pointer to a pointer to the custom stack.
 * @LineNumber: The line number where the pint operation is performed.
 */
void printTopInt(stack_t **custom_stack, unsigned int LineNumber)
{
	/* Check if the stack is empty */
	if (*custom_stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", LineNumber);
		free(glob.lineNumber);
		custom_free(*custom_stack);
		exit(EXIT_FAILURE);
	}

	/* Print the value of the top element as an integer */
	printf("%d\n", (*custom_stack)->n);
}

/**
 * printAll - function prints all elements of a custom stack.
 *
 * This function prints the values of all elements in the custom stack.
 *
 * @custom_stack: A pointer to a pointer to the custom stack.
 * @LineNumber: The line number where the pall operation is performed.
 */
void printAll(stack_t **custom_stack, unsigned int LineNumber)
{
	stack_t *now = *custom_stack;

	/* Traverse the stack and print each element */
	while (now != NULL)
	{
		printf("%d\n", now->n);
		now = now->next;
		(void)LineNumber; /* Unused parameter */
	}
}
