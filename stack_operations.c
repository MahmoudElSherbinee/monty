#include "monty.h"

/**
 * pushNewValue - function pushes a new value onto the stack
 * based on the specified mode.
 * This function allocates memory for a new stack node,
 * assigns the given value to it, and adjusts
 * the pointers accordingly based on the specified mode
 * (STACKMODE or QUEUEMODE).
 *
 * @upper: A pointer to the upper of the stack.
 * @lower: A pointer to the lowertom of the stack.
 * @value: The value to be pushed onto the stack.
 * @mode: The mode indicating whether to use STACKMODE or QUEUEMODE.
 *
 * Users can use this function to push values onto the stack
 * with different modes.
 */
void pushNewValue(stack_t **upper, stack_t **lower, int value, int mode)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		printf("Error: malloc failed\n");
		wrapExit(EXIT_FAILURE, NULL, *upper);
	}

	newNode->n = value;

	if (*upper == NULL)
	{
		newNode->prev = NULL;
		newNode->next = NULL;
		*upper = newNode;
		*lower = newNode;
	}
	else if (mode == S_M)
	{
		newNode->next = NULL;
		newNode->prev = *upper;
		(*upper)->next = newNode;
		*upper = newNode;
	}
	else if (mode == Q_M)
	{
		newNode->prev = NULL;
		newNode->next = *lower;
		(*lower)->prev = newNode;
		*lower = newNode;
	}
}

/**
 * popTopElement - function pops the upper element from the stack.
 * This function removes the upper element from the stack,
 * freeing the corresponding memory.
 *
 * @upper: A pointer to the upper of the stack.
 *
 * Users can use this function to pop elements from the stack.
 */
void popTopElement(stack_t **upper)
{
	stack_t *ptr = *upper;

	if (ptr == NULL)
	{
		wrapExit(EXIT_FAILURE, "can't pop an empty stack", *upper);
	}

	if (ptr->prev == NULL)
	{
		free(*upper);
		*upper = NULL;
	}
	else
	{
		ptr = ptr->prev;
		ptr->next = NULL;
		free(*upper);
		*upper = ptr;
	}
}

/**
 * swapTopElements - function swaps the upper two elements of the stack.
 * This function swaps the positions of the upper two elements in the stack.
 *
 * @upper: A pointer to the upper of the stack.
 * @lower: A pointer to the lowertom of the stack.
 *
 * Users can use this function to swap the upper two elements in the stack.
 */
void swapTopElements(stack_t **upper, stack_t **lower)
{
	stack_t *ptr = *upper;

	if (ptr == NULL || ptr->prev == NULL)
	{
		wrapExit(EXIT_FAILURE, "can't swap, stack too short", *upper);
	}

	ptr = ptr->prev;
	(*upper)->prev = ptr->prev;
	ptr->next = (*upper)->next;
	ptr->prev = *upper;
	(*upper)->next = ptr;
	*upper = ptr;

	if ((*lower)->prev != NULL)
	{
		*lower = (*lower)->prev;
	}
}
