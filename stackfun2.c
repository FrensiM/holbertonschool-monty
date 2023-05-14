#include "monty.h"
/**
 * _add - adds the two top elements of the stack together and update
 * stacks with the new value and removes one of the elements
 * @top: parameter refering to nodes
 * @line: lline number being read from monty file
 */
void _add(stack_t **top, unsigned int line)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	tmp = (*top)->next;
	tmp->n += (*top)->n;
	_pop(top, line);
}
/**
 * _nop - funcction that does nothing
 * @top: pointer
 * @line: line
 */
void _nop(stack_t **top, unsigned int line)
{
	(void) top;
	(void) line;
}
void _free(stack_t *top)
{
	stack_t *tmp;

	if (top == NULL)
		return;
	while (top != NULL)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
	free(top);
}
/**
 * file_error - function that prints the error for the file
 * @argv: argument value
 */
void file_error(char **argv)
{
	char *name = argv[1];

	fprintf(stderr, "Error: Can't open file %s\n", name);
	exit(EXIT_FAILURE);
}
/**
 * invalid_instruction - function that prints the error for
 * invalid opcode
 * @token: token
 * @line: line
 */
void invalid_instruction(char *token, unsigned int line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, token);
	exit(EXIT_FAILURE);
}
