#include "monty.h"
/**
 * _push - insert a node at head of list
 * @top: where to insert
 * @line: line number error
 */
void _push(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	new_node->prev = NULL;

	if (top == NULL)
	{
		new_node->next = NULL;
		*top = new_node;
	}
	else
	{
		new_node->next = *top;
		(*top)->prev = new_node;
		*top = new_node;
	}
}
/**
 * _pall - function that prints the elements of the
 * linked lists from the head to the end
 * @top: parameter refering to the nodes
 * @line: unused in this case
 */
void _pall(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp = *top;

	if (*top == NULL)
		return;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * _pint - function that prints the head of our stack
 * @top: parameter refering to the nodes
 * @line: line number being read from the monty file
 */
void _pint(stack_t **top, unsigned int line)
{
	if ((*top) != NULL)
		printf("%d\n", (*top)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line);
		exit(EXIT_FAILURE);
	}
}
/**
 * _pop - function that removes the first node of the stack
 * @top: parameter refering to our nodes
 * @line: line number being read from the monty file
 */
void _pop(stack_t **top, unsigned int line)
{
	stack_t *tmp;

	if ((*top) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack", line);
		exit(EXIT_FAILURE);
	}
	tmp = *top;
	if ((*top)->next == NULL)
	{
		free(*top);
		*top = NULL;
		return;
	}
	*top = tmp->next;
	(*top)->prev = NULL;
	free(tmp);
}
/**
 * _swap - swap the values of first 2 nodes
 * @top: head node list
 * @line: error line_number
 */
void _swap(stack_t **top, unsigned int line)
{
	int i;
	stack_t *tmp;

	for (i = 0; top[i] != NULL; i++)
		if (i < 2)
		{
			fprintf(stderr, "L%u: can't swap, stack too short", line);
			exit(EXIT_FAILURE);
		}
		else
		{
			tmp = ((*top)->next);
			(*top)->next = *top;
			*top = tmp;
		}
}
