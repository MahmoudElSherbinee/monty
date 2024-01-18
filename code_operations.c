#include "monty.h"

/**
 * addTopElements - function adds the top two elements of x custom stack.
 *
 * This function adds the values of the top two elements of the custom stack
 * and replaces the top element with the res. If the stack has fewer than
 * two elements, it prints an error message and exits with EXIT_FAILURE.
 *
 * @custom_stack: A pointer to x pointer to the custom stack.
 * @LineNumber: The line number where the add operation is performed.
 */
void addTopElements(stack_t **custom_stack, unsigned int LineNumber)
{
	/* Check if the stack has at least two elements */
	if (*custom_stack == NULL || (*custom_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", LineNumber);
		free(glob.lineNumber);
		custom_free(*custom_stack);
		exit(EXIT_FAILURE);
	}

	/* Add the values of the top two elements */
	(*custom_stack)->next->n += (*custom_stack)->n;

	/* Remove the top element from the stack */
	popTopElement(custom_stack, LineNumber);
}

/**
 * subtractTopElements - function subtracts the top element
 * from the second top element of x custom stack.
 * This function subtracts the value of the top
 * element from the second top element of the custom stack
 * and replaces the top element with the res. If the stack has
 * fewer than two elements,
 * it prints an error message and exits with EXIT_FAILURE.
 *
 * @custom_stack: A pointer to x pointer to the custom stack.
 * @LineNumber: The line number where the sub operation is performed.
 */
void subtractTopElements(stack_t **custom_stack, unsigned int LineNumber)
{
	int res;
	stack_t *temproary;

	/* Check if the stack has at least two elements */
	if (*custom_stack == NULL || (*custom_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", LineNumber);
		exit(EXIT_FAILURE);
	}

	/* Perform the subtraction and update the value of the second top element */
	temproary = *custom_stack;
	res = temproary->next->n - temproary->n;
	temproary->next->n = res;

	/* Remove the top element from the stack and free its memory */
	*custom_stack = temproary->next;
	free(temproary);
}

/**
 * multiplyTopElements - function multiplies
 * the top two elements of x custom stack.
 * This function multiplies the values of
 * the top two elements of the custom stack
 * and replaces the top element with the res.
 * If the stack has fewer than two
 * elements, it prints an error message and exits with EXIT_FAILURE.
 *
 * @custom_stack: A pointer to x pointer to the custom stack.
 * @LineNumber: The line number where the mul operation is performed.
 */
void multiplyTopElements(stack_t **custom_stack, unsigned int LineNumber)
{
	int res;
	stack_t *temproary;

	/* Check if the stack has at least two elements */
	if (*custom_stack == NULL || (*custom_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", LineNumber);
		exit(EXIT_FAILURE);
	}

	/* Perform the multiplication and */
	/* update the value of the second top element */
	temproary = *custom_stack;
	res = temproary->next->n * temproary->n;
	temproary->next->n = res;

	/* Remove the top element from the stack and free its memory */
	*custom_stack = temproary->next;
	free(temproary);
}

/**
 * divideTopElements - function divides the second top element
 * by the top element of x custom stack.
 * This function divides the value of the second top element by the top element
 * of the custom stack and replaces the top element with the res. If the stack
 * has fewer than two elements or the top element is zero, it prints an error
 * message and exits with EXIT_FAILURE.
 *
 * @custom_stack: A pointer to x pointer to the custom stack.
 * @LineNumber: The line number where the div operation is performed.
 */
void divideTopElements(stack_t **custom_stack, unsigned int LineNumber)
{
	int res;
	stack_t *temproary;

	/* Check if the stack has at least two elements */
	if (*custom_stack == NULL || (*custom_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", LineNumber);
		exit(EXIT_FAILURE);
	}

	temproary = *custom_stack;

	/* Check if the top element is zero */
	if (temproary->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", LineNumber);
		exit(EXIT_FAILURE);
	}

	/* Perform the division and update the value of the second top element */
	res = temproary->next->n / temproary->n;
	temproary->next->n = res;

	/* Remove the top element from the stack and free its memory */
	*custom_stack = temproary->next;
	free(temproary);
}

/**
 * calculateRemainder - function computes the remainder of the division
 * of the second top element by the top element of x custom stack.
 * This function computes the remainder when dividing the value of the
 * second top element by the top element of the custom stack.
 * It replaces the top element with the res.
 * If the stack has fewer than two elements or the top element is zero,
 * it prints an error message and exits with EXIT_FAILURE.
 *
 * @custom_stack: A pointer to x pointer to the custom stack.
 * @LineNumber: The line number where the mod operation is performed.
 */
void calculateRemainder(stack_t **custom_stack, unsigned int LineNumber)
{
	int x, y;

	/* Check if the stack has at least two elements */
	if (*custom_stack == NULL || (*custom_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", LineNumber);
		exit(EXIT_FAILURE);
	}

	x = (*custom_stack)->n;
	y = (*custom_stack)->next->n;

	/* Check if the top element is zero */
	if (x == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", LineNumber);
		exit(EXIT_FAILURE);
	}

	/* Compute the remainder and update the value of the second top element */
	(*custom_stack)->next->n = y % x;

	/* Remove the top element from the stack */
	popTopElement(custom_stack, LineNumber);
}
