#include "monty.h"
/**
 * get_op - fun pointer that takes argument of function in struct
 * @token: token
 * @line_number: line number
 * Return: return NULL
 */
void (*get_op(char *token, unsigned int line))(stack_t **stack,
unsigned int line_number)
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
	}
	invalid_instruction(token, line);
	return (NULL);
}
