#include "monty.h"
/**
 * _push - function that inserts new node in the beginning of the
 * doubly linked list
 * @top: pointer
 * @line: line
 */
void _push(stack_t **top, __attribute__((unused))unsigned int line)
{
	stack_t *new_Node = malloc(sizeof(stack_t));

	if (new_Node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_Node->n = data;
	new_Node->prev = NULL;

	if (*top == NULL)
	{
		new_Node->next = NULL;
		*top = new_Node;
	}
	else
	{
		new_Node->next = *top;
		(*top)->prev = new_Node;
		*top = new_Node;
	}
}
/**
 * _pall - function that prints all elements in a doubly linked list
 * @top: pointer
 * @line: line
 */
void _pall(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp = *top;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * _pint - function that prints the value of the top element
 * @top: pointer
 * @line: line
 */
void _pint(stack_t **top, unsigned int line)
{
	if (*top != NULL)
		printf("%d\n", (*top)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
}
/**
 * _pop - function that deletes the top element
 * @top: pointer
 * @line: line
 */
void _pop(stack_t **top, unsigned int line)
{
	stack_t *tmp = *top;

	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	tmp = tmp->next;
	free(*top);
	*top = tmp;
}
#include "monty.h"
/**
 * _add - function that adds top two elements of stack
 * @top: pointer
 * @line: line
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
