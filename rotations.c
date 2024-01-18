#include "monty.h"

/**
 * rotateRight - function rotates the elements of a custom stack to the right.
 *
 * This function rotates the elements of the custom stack to the right,
 * shifting the top element to the bottom. The rotation is performed a
 * specified number of times (LineNumber).
 *
 * @custom_stack: A pointer to a pointer to the custom stack.
 * @LineNumber: The number of rotations to be
 * performed (unused in this function).
 */
void rotateRight(stack_t **custom_stack,
				 __attribute__((unused)) unsigned int LineNumber)
{
	stack_t *temproary;

	temproary = *custom_stack;

	/* Check if the stack is empty or has only one element */
	if (*custom_stack == NULL || (*custom_stack)->next == NULL)
	{
		return;
	}

	/* Find the last element in the stack */
	while (temproary->next)
	{
		temproary = temproary->next;
	}

	/* Perform the rotation */
	temproary->next = *custom_stack;
	temproary->prev->next = NULL;
	temproary->prev = NULL;
	(*custom_stack)->prev = temproary;
	(*custom_stack) = temproary;
}

/**
 * rotateLeft - function rotates the elements of a custom stack to the left.
 *
 * This function rotates the elements of the custom stack to the left,
 * shifting the bottom element to the top. The rotation is performed a
 * specified number of times (LineNumber).
 *
 * @custom_stack: A pointer to a pointer to the custom stack.
 * @LineNumber: The number of rotations to be
 * performed (unused in this function).
 */
void rotateLeft(stack_t **custom_stack,
				__attribute__((unused)) unsigned int LineNumber)
{
	stack_t *temproary = *custom_stack, *man;

	/* Check if the stack is empty or has only one element */
	if (*custom_stack == NULL || (*custom_stack)->next == NULL)
	{
		return;
	}

	man = (*custom_stack)->next;
	man->prev = NULL;

	/* Find the last element in the stack */
	while (temproary->next != NULL)
	{
		temproary = temproary->next;
	}

	/* Perform the rotation */
	temproary->next = *custom_stack;
	(*custom_stack)->next = NULL;
	(*custom_stack)->prev = temproary;
	(*custom_stack) = man;
}
