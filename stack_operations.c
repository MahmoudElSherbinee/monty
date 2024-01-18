#include "monty.h"

/**
 * custom_free - fucntion frees the memory allocated for a custom stack.
 *
 * This function traverses the custom stack and frees each node,
 * releasing the memory occupied by the stack. It starts from the top
 * of the stack and iteratively frees each node until the stack is empty.
 *
 * @custom_stack: A pointer to the top of the custom stack.
 */

void custom_free(stack_t *custom_stack)
{
	stack_t *now;

	/* Traverse the stack and free each node */
	while (custom_stack != NULL)
	{
		now = custom_stack;
		custom_stack = custom_stack->next;
		free(now);
	}
}
/**
 * add_custom_node - function adds a new node
 * with the provided value to a custom stack.
 * This function allocates memory for a new node, initializes it with the
 * given value, and updates pointers to connect
 * the new node with the existing stack.
 * If the allocation fails, it prints an error message, frees the stack,
 * and exits the program with EXIT_FAILURE.
 *
 * @custom_stack: A pointer to a pointer to the custom stack.
 * @value: The value to be assigned to the new node.
 *
 * Return: A pointer to the newly created node.
 */

stack_t *add_custom_node(stack_t **custom_stack, const int value)
{
	stack_t *NewNode;

	/* Allocate memory for the new node */
	NewNode = malloc(sizeof(stack_t));
	if (NewNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		custom_free(*custom_stack);
		exit(EXIT_FAILURE);
	}

	/* Initialize the new node with the provided value */
	NewNode->n = value;
	NewNode->prev = NULL;

	/* Update pointers to connect the new node with the existing stack */
	if (*custom_stack == NULL)
		NewNode->next = NULL;
	else
	{
		NewNode->next = *custom_stack;
		(*custom_stack)->prev = NewNode;
	}

	/* Update the stack to point to the new node */
	*custom_stack = NewNode;

	return (NewNode);
}

/**
 * pushNewValue - function pushes a new value onto the stack
 * based on the specified mode.
 * This function allocates memory for a new stack node,
 * assigns the given value to it, and adjusts
 * the pointers accordingly based on the specified mode
 * (STACKMODE or QUEUEMODE).
 *
 * @custom_stack: A pointer to the upper of the stack.
 * @LineNumber: The value to be pushed onto the stack.
 *
 * Users can use this function to push values onto the stack
 * with different modes.
 */

void pushNewValue(stack_t **custom_stack, unsigned int LineNumber)
{
	int value;

	/* Check if the scriptBuffer is provided and is a valid number */
	if (glob.scriptBuffer == NULL ||
		!isNumericString(glob.scriptBuffer))
	{
		fprintf(stderr, "L%d: usage: push integer\n", LineNumber);
		custom_free(*custom_stack);
		fclose(glob.scriptFile);
		free(glob.lineNumber);
		exit(EXIT_FAILURE);
	}

	/* Convert the scriptBuffer to an integer */
	value = atoi(glob.scriptBuffer);

	if (glob.val == 0)
	{
		/* Add the integer to the stack */
		if (add_custom_node(custom_stack, value) == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			custom_free(*custom_stack);
			fclose(glob.scriptFile);
			free(glob.lineNumber);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		Prepaire_queue(custom_stack, value);
	}
}

/**
 * popTopElement - function pops the top element from a custom stack.
 * This function removes the top element from the custom stack,
 * updating the stack pointer and freeing the memory of the popped node.
 * If the stack is empty, it prints an error message
 * and exits with EXIT_FAILURE.
 *
 * @custom_stack: A pointer to a pointer to the custom stack.
 * @LineNumber: The line number where the pop operation is performed.
 */
void popTopElement(stack_t **custom_stack, unsigned int LineNumber)
{
	stack_t *temporary;

	/* Check if the stack is empty */
	if (*custom_stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", LineNumber);
		free(glob.lineNumber);
		custom_free(*custom_stack);
		exit(EXIT_FAILURE);
	}

	temporary = (*custom_stack)->next;

	free(*custom_stack);

	*custom_stack = temporary;

	if (*custom_stack != NULL)
		(*custom_stack)->prev = NULL;
}

/**
 * swapTopElements - function swaps the top two elements of a custom stack.
 *
 * This function swaps the positions of the
 * top two elements in the custom stack.
 * If the stack has fewer than two elements,
 * it prints an error message and exits
 * with EXIT_FAILURE.
 *
 * @custom_stack: A pointer to a pointer to the custom stack.
 * @LineNumber: The line number where the swap operation is performed.
 */
void swapTopElements(stack_t **custom_stack, unsigned int LineNumber)
{
	stack_t *temporary;

	/* Check if the stack has at least two elements */
	if (*custom_stack == NULL || (*custom_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", LineNumber);
		free(glob.lineNumber);
		custom_free(*custom_stack);
		exit(EXIT_FAILURE);
	}

	/* Save the second element in the stack */
	temporary = (*custom_stack)->next;

	/* Update pointers to swap the positions of the top two elements */
	(*custom_stack)->next = temporary->next;

	if (temporary->next != NULL)
		temporary->next->prev = *custom_stack;

	temporary->prev = NULL;
	temporary->next = *custom_stack;
	(*custom_stack)->prev = temporary;

	/* Update the stack pointer to point to the new top element */
	*custom_stack = temporary;
}
