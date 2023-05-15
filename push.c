#include "monty.h"
void _push(stack_t **top, unsigned int line_number)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    nread = getline(&line, &len, stdin);

    if (nread == -1)
    {
        fprintf(stderr, "L%i: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value;
    char *endptr;
    value = strtol(line, &endptr, 10);

    if (*endptr != '\n')
    {
        fprintf(stderr, "L%i: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *top;

    if (*top != NULL)
        (*top)->prev = new_node;

    *top = new_node;

    free(line);
}

