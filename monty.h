#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

/* DATA STRUCTURES */
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
/* op func */
void _push(stack_t **top, __attribute__((unused)) unsigned int line); 
void _pall(stack_t **top, __attribute__((unused)) unsigned int line);
void _pint(stack_t **top, unsigned int line);
void _pop(stack_t **top, unsigned int line);
void _swap(stack_t **top, unsigned int line);
void _add(stack_t **top, unsigned int line);
void _nop(stack_t **top, unsigned int line);
void _free(stack_t *top);
int is_num(char *n);
void invalid_instruction(char *token, unsigned int line);
void (*get_op(char *token, unsigned int line))(stack_t **, unsigned int);
void open_file(char **argv);
int is_comment(char *token, unsigned int line);
void file_error(char **argv);
/*global variable */
int data;
#endif
