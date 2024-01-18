#include "monty.h"

/**
 * my_custom_stack - function placeholder function for custom stack operations.
 *
 * This function does not perform any specific operations on the custom stack
 * and only serves as a placeholder. It takes the custom stack and line number
 * as parameters without using them. Modify the function to implement the
 * desired functionality.
 *
 * @custom_stack: A pointer to a pointer to the custom stack.
 * @LineNumber: The line number where the operation is performed.
 */
void my_custom_stack(stack_t **custom_stack, unsigned int LineNumber)
{
	/* Placeholder function, no specific operations performed */
	(void)custom_stack; /* Unused parameter */
	(void)LineNumber;	/* Unused parameter */
	glob.val = 0;
}

/**
 * Prepaire_queue - function Adds a new node with a given
 * value to the end of a linked list.
 *
 * This function creates a new node with the provided value and adds it to
 * the end of the linked list. If the linked list is empty, the new node
 * becomes the custom_stack of the list.
 *
 * @custom_stack: A pointer to the custom_stack of the linked list.
 * @value: The value to be added to the new node.
 */

void Prepaire_queue(stack_t **custom_stack, unsigned int value)
{
	stack_t *NewNode, *man;

	man = *custom_stack;

	/* Allocate memory for the new node */
	NewNode = malloc(sizeof(stack_t));
	if (NewNode == NULL)
	{
		fprintf(stderr, "Error\n");
	}

	/* Initialize the new node with the provided value */
	NewNode->n = value;
	NewNode->next = NULL;

	/* Find the last node in the linked list */
	if (man)
	{
		while (man->next)
			man = man->next;
	}

	/* Add the new node to the linked list */
	if (!man)
	{
		/* If the list is empty, the new node becomes the custom_stack */
		*custom_stack = NewNode;
		NewNode->prev = NULL;
	}
	else
	{
		man->next = NewNode;
		NewNode->prev = man;
	}
}
/**
 * my_custom_queue - function placeholder function for custom queue operations.
 *
 * This function does not perform any specific operations on the custom queue
 * and only serves as a placeholder. It takes the custom queue and line number
 * as parameters without using them. Modify the function to implement the
 * desired functionality.
 *
 * @custom_queue: A pointer to a pointer to the custom queue.
 * @LineNumber: The line number where the operation is performed.
 */

void my_custom_queue(stack_t **custom_queue, unsigned int LineNumber)
{
	(void)custom_queue;
	(void)LineNumber;
	glob.val = 1;
}
