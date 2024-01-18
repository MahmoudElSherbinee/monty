#include "monty.h"
/**
 * custom_execute - function executes operations from a file on a custom stack.
 * This function reads lines from the file, extracts the opcode and argument,
 * and executes the corresponding operation on the custom stack. It skips
 * comments and empty lines.
 *
 * @custom_stack: A pointer to a pointer to the custom stack.
 */
void custom_execute(stack_t **custom_stack)
{
	char *operation_code = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;

	while ((nread = getline(&glob.lineNumber,
													&len, glob.scriptFile)) != -1)
	{
		line_number++;
		operation_code = strtok(glob.lineNumber, " \t\r\n\a");
		glob.scriptBuffer = strtok(NULL, " \n\t");

		/* Skip comments and empty lines */
		if (operation_code == NULL || *operation_code == '#')
			continue;

		execute_operation_code(operation_code, custom_stack, line_number);
	}
}
