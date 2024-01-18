#include "monty.h"

MontyGlobal glob;
/**
 * cunstom_nop - function does nothing (no operation).
 *
 * This function serves as a placeholder for a no-operation (nop).
 * It takes the custom custom_stack and line number
 * as parameters but doesn't perform any action.
 *
 * @custom_stack: A pointer to a pointer to the custom custom_stack.
 * @LineNumber: The line number where the nop operation is encountered.
 */
void cunstom_nop(stack_t **custom_stack, unsigned int LineNumber)
{
	/* Do nothing */
	(void)custom_stack;
	(void)LineNumber;
}


/**
 * main - entry point for the monty program
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 *
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
	stack_t *custom_stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	glob.scriptFile = fopen(argv[1], "r");
	if (glob.scriptFile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	custom_execute(&custom_stack);
	fclose(glob.scriptFile);
	free(glob.lineNumber);
	custom_free(custom_stack);
	exit(EXIT_SUCCESS);
}
