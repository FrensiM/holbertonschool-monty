#include "monty.h"
/**
 * usage_error - function that prints the error for usage of the file
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
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
