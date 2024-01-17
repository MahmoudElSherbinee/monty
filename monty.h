#ifndef MONTY_H
#define MONTY_H

/* Include libraries */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/*  ------------------------------------------- */
/* Define Modes */
#define S_M 0
#define Q_M 1

/* -------------------------------------------- */

/* STRUCTS */
/* main structs */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* my structs */

/**
 * union functype_union - Defines a union named functype_union that
 * encapsulates three function pointers.
 * This union includes function pointers for operating on a stack, offering
 * functionality such as manipulating the top only,
 * pushing with a specific mode,
 * and interacting with both the top and bottom of the stack.
 *
 * The function pointers within this union are:
 * @operate_top_only:
 *					A function to perform operations on the top of the stack.
 * @operate_push_mode:
 *					A function to push a value onto the stack with a specified mode.
 * @operate_top_bottom:
 *					A function to operate on both the top and bottom of the stack.
 *
 * Users should ensure that the appropriate function pointers
 * are assigned and implemented for desired stack operations.
 */

union functype_union
{
	void (*operate_top_only)(stack_t **upper);
	void (*operate_push_mode)(stack_t **upper,
							  stack_t **lower, int value, int mode);
	void (*operate_top_bottom)(stack_t **upper, stack_t **lower);
};

/**
 * struct OperationType - Represents a structure named OperationType,
 * combining an operation code with a union of Monty stack operations.
 * This structure associates an operation code,
 * represented as a character pointer, with a union
 * named functype_union that encapsulates various stack manipulation functions.
 * It is designed to provide a convenient way to link specific operations with
 * their corresponding operation codes.
 *
 * The members of the OperationType structure are:
 * @operationCode: A character pointer representing the operation code.
 * @operation_function: A union of Monty stack operation functions
 * (functype_union) related to the operation code.
 *
 * Users can use this structure to associate operation codes
 * with specific stack manipulation functions.
 */
typedef struct OperationType
{
	/**< Operation code associated with the structure. */
	char *operationCode;
	/**< Union of Monty stack operation functions for the operation code. */
	union functype_union operation_function;
} OperationType;

/**
 * struct MontyGlobal - Represents a structure named MontyGlobal,
 * encapsulating information related to Monty scripting.
 * This structure includes members for managing a script buffer,
 * tracking line numbers, and holding a file pointer
 * for Monty script operations.
 *
 * The members of the MontyGlobal structure are:
 * @scriptBuffer: A character pointer representing the script buffer.
 * @lineNumber: An unsigned long integer representing the current line number
 * in the script.
 * @scriptFile: A FILE pointer representing the Monty script file.
 *
 * Users can use this structure to manage global information
 * related to Monty scripting.
 */
typedef struct MontyGlobal
{
	char *scriptBuffer;		  /**< Script buffer associated with the structure. */
	unsigned long lineNumber; /**< Current line number in the Monty script. */
	FILE *scriptFile;		  /**< FILE pointer for Monty script operations. */
} MontyGlobal;

/* -------------------------------------------- */


/* //// FUNCTIONS //// */

/* STACK OPERATIONS */
void pushNewValue(stack_t **upper, stack_t **lower, int value, int mode);
void popTopElement(stack_t **upper);
void swapTopElements(stack_t **upper, stack_t **lower);

/* ROTATIONS */
void rotateRight(stack_t **upper, stack_t **lower);
void rotateLeft(stack_t **upper, stack_t **lower);


/* PRINTERS */
void printChar(stack_t **upper);
void printString(stack_t **upper);
void printTopInt(stack_t **upper);
void printAll(stack_t **upper);


/* CODE OPERAIONS */
void addTopElements(stack_t **upper);
void subtractTopElements(stack_t **upper);
void multiplyTopElements(stack_t **upper);
void divideTopElements(stack_t **upper);
void calculateRemainder(stack_t **upper);


/* NUMERIC STRING CHECKER */
int isNumericString(char *s);

/* OPERATION TYPE */
OperationType *operation_type();

int customParser(OperationType *operations);

/* EXIT */
void wrapExit(int code, char *message, stack_t *upper);

#endif /* MONTY_H */
