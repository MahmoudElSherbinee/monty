#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <string.h>

#define MONTYOPCT 14

static MontyGlobal monty_global;

/**
 * wrapExit - function wraps the exit process with additional
 * functionality, printing an exit message and freeing resources.
 * This function takes an exit code, an exit string, and
 * a stack pointer as parameters. It prints the exit string (if provided)
 * along with the corresponding line number, frees the stack memory,
 * frees the script buffer, closes the script file,
 * and exits the program with the given exit code.
 *
 * @code: The exit code for the program.
 * @	message: The exit string to be printed (can be NULL).
 * @upper: A pointer to the upper of the stack.
 *
 * Users can utilize this function to perform cleanup tasks
 * and exit the program with custom messages.
 */
void wrapExit(int code, char *message, stack_t *upper)
{
	stack_t *ptr = upper;

	if (message != NULL)
	{
		printf("L%lu: %s\n", monty_global.lineNumber, message);
	}

	while (upper != NULL)
	{
		ptr = upper->prev;
		free(upper);
		upper = ptr;
	}

	free(monty_global.scriptBuffer);
	fclose(monty_global.scriptFile);
	exit(code);
}

/**
 * Custom parser - function for interpreting a custom script language.
 * This function reads a custom script from a file, processes the script,
 * and executes corresponding custom operations. It utilizes a custom stack
 * with push, pop, and other operations defined in the given operations array.
 *
 * @operations: An array of OperationType representing supported operations.
 *
 * Return: Returns 0 on successful execution, EXIT_FAILURE on failure.
 */

int customParser(OperationType *operations)
{
	/* Initialize variables */
	size_t length = 0, value, mode = S_M;
	stack_t *upper = NULL;
	stack_t *lower = NULL;
	char *token;

	/* Read lines from the script until the end is reached */
	while (getline(&monty_global.scriptBuffer,
												&length, monty_global.scriptFile) > 0)
	{
		/* Check for memory allocation failure */
		if (monty_global.scriptBuffer == NULL)
		{
			printf("Error: malloc failed\n");
			wrapExit(EXIT_FAILURE, NULL, upper);
		}

		/* Tokenize the line using newline and space as delimiters */
		token = strtok(monty_global.scriptBuffer, "\n ");

		/* Process each token */
		if (token != NULL)
		{
			value = 0;

			/* Check for comments or "nop" instruction */
			if (*token == '#' || !strcmp(token, "nop"))
				; /* Do nothing for comments or "nop" */

			/* Check for "queue" instruction */
			else if (!strcmp(token, "queue"))
				mode = Q_M;

			/* Check for "stack" instruction */
			else if (!strcmp(token, "stack"))
				mode = S_M;

			/* Process other instructions */
			else
			{
				/* Find the index of the operation in the operations array */
				while (value < MONTYOPCT && strcmp(token, operations[value].operationCode))
					value++;

				/* Process based on the operation type */
				if (value == 0)
				{
					/* Handle custom_push instruction */
					token = strtok(NULL, "\n ");
					if (token == NULL || !isNumericString(token))
						wrapExit(EXIT_FAILURE, "usage: push integer", upper);
					operations[0].operation_function.operate_push_mode(&upper, &lower, atoi(token), mode);
				}
				else if (value < 4)
					/* Handle operations with customTopBottom function */
					operations[value].operation_function.operate_top_bottom(&upper, &lower);
				else if (value < MONTYOPCT)
					/* Handle operations with customTopOnly function */
					operations[value].operation_function.operate_top_only(&upper);
				else
				{
					/* Handle unknown instruction */
					printf("L%ld: unknown instruction %s\n", monty_global.lineNumber, token);
					wrapExit(EXIT_FAILURE, NULL, upper);
				}
			}
		}

		/* Free allocated memory and reset variables */
		free(monty_global.scriptBuffer);
		monty_global.scriptBuffer = NULL;
		length = 0;
		monty_global.lineNumber++;
	}

	/* Exit the function with success status */
	wrapExit(EXIT_SUCCESS, NULL, upper);
	return 0;
}


/**
 * operation_type - function creates and initializes
 * an array of OperationType for supported operations.
 * This function initializes an array of OperationType, each representing
 * a specific operation in the Monty language. The array includes information
 * about operation codes and corresponding function pointers to execute
 * the operations.
 *
 * Return:  Returns a pointer to the array of
 * OperationType representing supported operations.
 */

OperationType *operation_type()
{
	/* Declare a static array of OperationType with 14 elements. */
	static OperationType h[14];
	/* STACK OPERATIONS */
	h[0].operationCode = "push";
	h[0].operation_function.operate_push_mode = pushNewValue;
	h[1].operationCode = "pop";
	h[1].operation_function.operate_top_only = popTopElement;
	h[2].operationCode = "swap";
	h[2].operation_function.operate_top_bottom = swapTopElements;
	/* ------------------------------------------------------------- */
	/* ROTATIONS */
	h[3].operationCode = "rotr";
	h[3].operation_function.operate_top_bottom = rotateRight;

	h[4].operationCode = "rotl";
	h[4].operation_function.operate_top_bottom = rotateLeft;
	/* ------------------------------------------------------------- */
	/* PRINTERS */
	h[5].operationCode = "pchar";
	h[5].operation_function.operate_top_only = printChar;
	h[6].operationCode = "pstr";
	h[6].operation_function.operate_top_only = printString;
	h[7].operationCode = "pint";
	h[7].operation_function.operate_top_only = printTopInt;
	h[8].operationCode = "pall";
	h[8].operation_function.operate_top_only = printAll;
	/* ------------------------------------------------------------- */
	/* CODE OPERAIONS */
	h[9].operationCode = "add";
	h[9].operation_function.operate_top_only = addTopElements;
	h[10].operationCode = "sub";
	h[10].operation_function.operate_top_only = subtractTopElements;
	h[11].operationCode = "mul";
	h[11].operation_function.operate_top_only = multiplyTopElements;
	h[12].operationCode = "div";
	h[12].operation_function.operate_top_only = divideTopElements;
	h[13].operationCode = "mod";
	h[13].operation_function.operate_top_only = calculateRemainder;
	/* Return the array of OperationType. */
	return (h);
}

/**
 * main - function for the Monty interpreter.
 * This function serves as the entry point for the Monty interpreter.
 * It reads a Monty script from a file, processes the script, and
 * executes the corresponding operations.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return:  Returns 0 on successful execution, EXIT_FAILURE on failure.
 */

int main(int argc, char *argv[])
{

	OperationType *operations;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	monty_global.scriptFile = fopen(argv[1], "r");
	if (monty_global.scriptFile == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	operations = operation_type();
	monty_global.lineNumber = 1;
	customParser(operations);

	return (0);
}
#undef MONTYOPCT
