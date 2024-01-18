#include "monty.h"
/**
 * execute_operation_code - function executes the operation
 * corresponding to the given operation_code.
 * This function searches for the operation_codein the instruction set
 * and calls the associated function to perform the operation.
 * If the operation_code is not recognized,
 * it prints an error message and exits with EXIT_FAILURE.
 *
 * @operation_code: The operation_code representing
 * the operation to be executed.
 * @custom_stack: A pointer to a pointer to the custom stack.
 * @LineNumber: The line number where the operation is performed.
 */
void execute_operation_code(char *operation_code, stack_t **custom_stack,
							unsigned int LineNumber)
{
	instruction_t instructions[] = {
		/* STACK OPERATIONS */
		{"push", pushNewValue},
		{"pop", popTopElement},
		{"swap", swapTopElements},
		/* PRINTERS */
		{"pchar", printChar},
		{"pstr", printString},
		{"pall", printAll},
		{"pint", printTopInt},
		/* CODE OPERAIONS */
		{"add", addTopElements},
		{"sub", subtractTopElements},
		{"mul", multiplyTopElements},
		{"div", divideTopElements},
		{"mod", calculateRemainder},
		/* ROTATIONS */
		{"rotr", rotateRight},
		{"rotl", rotateLeft},
		/* Stack */
		{"stack", my_custom_stack},
		/* Queue */
		{"queue", my_custom_queue},
		{"nop", cunstom_nop},
		{NULL, NULL}};
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(operation_code, instructions[i].opcode) == 0)
		{	instructions[i].f(custom_stack, LineNumber);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", LineNumber, operation_code);
	custom_free(*custom_stack);
	fclose(glob.scriptFile);
	free(glob.lineNumber);
	exit(EXIT_FAILURE);
}
