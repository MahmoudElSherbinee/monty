#include "monty.h"

/**
 * addTopElements - function adds the upper two elements of the stack.
 * This function adds the values of the upper two elements
 * in the stack and updates the stack accordingly.
 *
 * @upper: A pointer to the upper of the stack.
 *
 * Users can use this function to add the upper two elements in the stack.
 */
void addTopElements(stack_t **upper)
{
	stack_t *ptr = *upper;
	long number;

	/*
	 * Check if there are enough elements in the stack to perform the addition.
	 * If not, exit with an error message.
	 */
	if (ptr == NULL || ptr->prev == NULL)
	{
		wrapExit(EXIT_FAILURE, "can't add, stack too short", *upper);
	}
	else
	{
		/* Store the value of the upper element. */
		number = ptr->n;

		/* Move the pointer to the second-upper element. */
		ptr = ptr->prev;

		/*
		 * Adjust the pointers and free the memory of the upper element.
		 */
		ptr->next = NULL;
		free(*upper);
		*upper = ptr;

		/* Update the second-upper element by adding the upper element's value. */
		ptr->n += number;
	}
}

/**
 * subtractTopElements - function subtracts the upper element
 * from the second-upper element in the stack.
 * This function subtracts the value of the second-upper element
 * from the upper element in the stack
 * and updates the stack accordingly.
 *
 * @upper: A pointer to the upper of the stack.
 *
 * Users can use this function to subtract the upper element
 * from the second-upper element in the stack.
 */
void subtractTopElements(stack_t **upper)
{
	stack_t *ptr = *upper;
	long number;

	/*
	 * Check if there are enough elements in the stack to perform the subtraction.
	 * If not, exit with an error message.
	 */
	if (ptr == NULL || ptr->prev == NULL)
	{
		wrapExit(EXIT_FAILURE, "can't sub, stack too short", *upper);
	}
	else
	{
		/* Store the value of the upper element. */
		number = ptr->n;

		/* Move the pointer to the second-upper element. */
		ptr = ptr->prev;

		/*
		 * Adjust the pointers and free the memory of the upper element.
		 */
		ptr->next = NULL;
		free(*upper);
		*upper = ptr;

		/* Update the second-upper element by */
		/* subtracting the upper element's value. */
		ptr->n -= number;
	}
}

/**
 * multiplyTopElements - function multiplies upper two elements of the stack
 * This function multiplies the value of the second-upper element
 * with the upper element in the stack and updates the stack accordingly.
 *
 * @upper: A pointer to the upper of the stack.
 *
 * Users can use this function to multiply the upper two elements in the stack.
 */
void multiplyTopElements(stack_t **upper)
{
	stack_t *ptr = *upper;
	long number;

	/*
	 * Check if there are enough elements in the stack
	 * to perform the multiplication.
	 * If not, exit with an error message.
	 */
	if (ptr == NULL || ptr->prev == NULL)
	{
		wrapExit(EXIT_FAILURE, "can't mul, stack too short", *upper);
	}
	else
	{
		/* Store the value of the upper element. */
		number = ptr->n;

		/* Move the pointer to the second-upper element. */
		ptr = ptr->prev;

		/*
		 * Adjust the pointers and free the memory of the upper element.
		 */
		ptr->next = NULL;
		free(*upper);
		*upper = ptr;

		/* Update the second-upper element by */
		/* multiplying it with the upper element's value. */
		ptr->n *= number;
	}
}

/**
 * divideTopElements - function divides the second-upper element
 * by the upper element in the stack.
 * This function divides the value of the second-upper element
 * by the upper element in the stack
 * and updates the stack accordingly.
 *
 * @upper: A pointer to the upper of the stack.
 *
 * Users can use this function to perform division in the stack.
 */
void divideTopElements(stack_t **upper)
{
	stack_t *ptr = *upper;
	long number;

	/*
	 * Check if there are enough elements in the stack to perform the division.
	 * If not, exit with an error message.
	 */
	if (ptr == NULL || ptr->prev == NULL)
	{
		wrapExit(EXIT_FAILURE, "can't div, stack too short", *upper);
	}
	else
	{
		/* Store the value of the upper element. */
		number = ptr->n;

		/*
		 * Check if division by zero would occur.
		 * If so, exit with an error message.
		 */
		if (number == 0)
		{
			wrapExit(EXIT_FAILURE, "division by zero", *upper);
		}

		/* Move the pointer to the second-upper element. */
		ptr = ptr->prev;

		/*
		 * Adjust the pointers and free the memory of the upper element.
		 */
		ptr->next = NULL;
		free(*upper);
		*upper = ptr;

		/* Update the second-upper element by */
		/* dividing it by the upper element's value. */
		ptr->n /= number;
	}
}

/**
 * calculateRemainder - function computes the remainder after
 * dividing the second-upper element by the upper element in the stack.
 * This function computes the remainder after dividing
 * the value of the second-upper element by the
 * upper element in the stack and updates the stack accordingly.
 *
 * @upper: A pointer to the upper of the stack.
 *
 * @note Users can use this function to calculate the remainder in the stack.
 */
void calculateRemainder(stack_t **upper)
{
	stack_t *ptr = *upper;
	long number;

	/*
	 * Check if there are enough elements in the stack
	 * to perform the remainder calculation.
	 * If not, exit with an error message.
	 */
	if (ptr == NULL || ptr->prev == NULL)
	{
		wrapExit(EXIT_FAILURE, "can't mod, stack too short", *upper);
	}
	else
	{
		/* Store the value of the upper element. */
		number = ptr->n;

		/*
		 * Check if division by zero would occur.
		 * If so, exit with an error message.
		 */
		if (number == 0)
		{
			wrapExit(EXIT_FAILURE, "division by zero", *upper);
		}

		/* Move the pointer to the second-upper element. */
		ptr = ptr->prev;

		/*
		 * Adjust the pointers and free the memory of the upper element.
		 */
		ptr->next = NULL;
		free(*upper);
		*upper = ptr;

		/* Update the second-upper element by calculating the remainder. */
		ptr->n %= number;
	}
}
