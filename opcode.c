#include "monty.h"
/**
 *
 */
void (*get_op(char *token, unsigned int line))
(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t op[] = {{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL},
	};
	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(token, op[i].opcode) == 0)
		
			return (op[i].f);
/*
			if (token[1] == NULL)
			{
				fprintf(stderr, "L%i: usage: push integer\n", y);
				exit(EXIT_FAILURE);
			}
			*stack_t = _push(stack, line_number, token[1]);
			if (stack_t == NULL)
				exit(EXIT_FAILURE);
		}
	}
*/
	if (op[i].opcode == NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", y, token_array[0]);
		exit(EXIT_FAILURE);
	}
}
