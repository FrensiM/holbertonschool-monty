#include "monty.h"
/**
 * _swap - function that swaps top two elements of stack
 * @top: pointer
 * @line: line
 */
void _swap(stack_t **top, unsigned int line)
{
	int tmp_num;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	tmp_num = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = tmp_num;
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
