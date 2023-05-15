#include "monty.h"
/**
 * open_file - function that opens the file
 * @argv: argument value
 */
void open_file(char **argv)
{
	void (*p_func)(stack_t **, unsigned int);
	ssize_t line;
	FILE *fp;
	char *buff = NULL, *token = NULL, command[1024];
	size_t length = 0;
	unsigned int line_counter = 1;
	stack_t *top = NULL;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		file_error(argv);
	while ((line = getline(&buff, &length, fp)) != -1)
	{
		token = strtok(buff, "\n\t\r ");
		if (*token == '\0')
			continue;
		strcpy(command, token);
		if (is_comment(token, line_counter) == 1)
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\r ");
			data = atoi(token);
			if (token == NULL || !is_num(token))
			{
				fprintf(stderr, "L%i: usage: push integer\n", line_counter);
				exit(EXIT_FAILURE);
			}
			p_func = get_op(command, line_counter);
			p_func(&top, line_counter);
		}
		else
		{
			p_func = get_op(token, line_counter);
			p_func(&top, line_counter);
		}
		line_counter++;
	}
	fclose(fp);
	if (buff != NULL)
		free(buff);
	_free(top);
}
/**
 * is_comment - func that find if it is coment
 * @token: token
 * @line: line nr
 * Return: -1 or 1
 */
int is_comment(char *token, unsigned int line)
{
	if (token[0] == '#')
	{
		line++;
		return (1);
	}
	return (-1);
}
