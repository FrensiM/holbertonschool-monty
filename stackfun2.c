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
