#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

/* LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
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
	char *lineNumber; /**< Current line number in the Monty script. */
	FILE *scriptFile;		  /**< FILE pointer for Monty script operations. */
} MontyGlobal;

extern MontyGlobal glob;
/* -------------------------------------------- */


/* //// FUNCTIONS //// */

/* STACK OPERATIONS */
stack_t *add_custom_node(stack_t **custom_stack, const int value);
void custom_free(stack_t *custom_stack);
void pushNewValue(stack_t **custom_stack, unsigned int LineNumber);
void popTopElement(stack_t **custom_stack, unsigned int LineNumber);
void swapTopElements(stack_t **custom_stack, unsigned int LineNumber);


/* PRINTERS */
void printChar(stack_t **custom_stack, unsigned int LineNumber);
void printString(stack_t **custom_stack, unsigned int LineNumber);
void printTopInt(stack_t **custom_stack, unsigned int LineNumber);
void printAll(stack_t **custom_stack, unsigned int LineNumber);

/* ROTATIONS */
void rotateRight(stack_t **custom_stack,
				 __attribute__((unused)) unsigned int LineNumber);
void rotateLeft(stack_t **custom_stack,
				__attribute__((unused)) unsigned int LineNumber);

/* CODE OPERAIONS */
void addTopElements(stack_t **custom_stack, unsigned int LineNumber);
void subtractTopElements(stack_t **custom_stack, unsigned int LineNumber);
void multiplyTopElements(stack_t **custom_stack, unsigned int LineNumber);
void divideTopElements(stack_t **custom_stack, unsigned int LineNumber);
void calculateRemainder(stack_t **custom_stack, unsigned int LineNumber);

/* NUMERIC STRING CHECKER */
int isNumericString(char *s);

/* EXECUTION */
void custom_execute(stack_t **custom_stack);
void execute_operation_code(char *operation_code, stack_t **custom_stack,
							unsigned int LineNumber);


/* main */
void cunstom_nop(stack_t **custom_stack, unsigned int LineNumber);
#endif /* MONTY_H */
