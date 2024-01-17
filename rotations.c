#include "monty.h"

/**
 * rotateRight - function rotates the stack to the right,
 * moving the bottom element to the upper.
 * This function rotates the stack to the right,
 * moving the bottom element to the upper,
 * and updates the stack pointers accordingly.
 *
 * @upper: A pointer to the upper of the stack.
 * @lower: A pointer to the bottom of the stack.
 *
 * @note Users can use this function to perform a right rotation on the stack.
 */
void rotateRight(stack_t **upper, stack_t **lower)
{
	stack_t *upper_ptr = *upper, *lower_ptr = *lower;

	/* Check if there are enough elements in the stack to perform the rotation */
	if (upper_ptr == NULL || upper_ptr->prev == NULL)
	{
		return;
	}

	/* Adjust pointers to perform the right rotation */
	upper_ptr->next = lower_ptr;
	lower_ptr->prev = upper_ptr;
	*lower = lower_ptr->next;
	(*lower)->prev = NULL;
	*upper = lower_ptr;
	lower_ptr->next = NULL;
}

/**
 * rotateLeft - function rotates the stack to the left,
 * moving the upper element to the lower.
 * This function rotates the stack to the left,
 * moving the upper element to the lower,
 * and updates the stack pointers accordingly.
 *
 * @upper: A pointer to the upper of the stack.
 * @lower: A pointer to the lower of the stack.
 *
 * Users can use this function to perform a left rotation on the stack.
 */
void rotateLeft(stack_t **upper, stack_t **lower)
{
	stack_t *upper_ptr = *upper, *lower_ptr = *lower;

	/* Check if there are enough elements in the stack to perform the rotation */
	if (upper_ptr == NULL || upper_ptr->prev == NULL)
	{
		return;
	}

	/* Adjust pointers to perform the left rotation */
	upper_ptr->next = lower_ptr;
	lower_ptr->prev = upper_ptr;
	*upper = upper_ptr->prev;
	(*upper)->next = NULL;
	*lower = upper_ptr;
	upper_ptr->prev = NULL;
}
