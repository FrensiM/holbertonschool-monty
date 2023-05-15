#include "monty.h"

/**
 * _push - insert a node at head of list
 * @top: where to insert
 * @line_number: line number error
 * @n: argument for push
 * Return: new head
 */
void _push(stack_t **top, unsigned int line_number)
{
	stack_t *new;
	char *data_str = strtok(NULL, " \n\t\r");
	int is_nr = is_num(data_str);

	if (data_str == NULL || is_nr)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "can't allocate memory\n");
		exit(EXIT_FAILURE);
	}
	new->n = data;
	new->prev = NULL;
	new->next = *top;
	if (*top != NULL)
		(*top)->prev = new;
	*top = new;
}

/**
 * is_num - checks if string contains a num
 * @n: string to check
 * Return: 0 if num, 1 if else
 */
int is_num(char *n)
{
	int i = 0;

	while (n[i] != '\0')
	{
		if (n[0] == '-')
		{
			i++;
			continue;
		}
		if (n[0] == '\n')
			return (1);
		if (n[i] == '\n')
			break;
		if (n[i] < 48 || n[i] > 57)
			return (1);
		i++;
	}
	return (0);
}
