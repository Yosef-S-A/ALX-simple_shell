#include "shell.h"

/**
 * break_line - separetes an input to command and argument
 * @line: user input
 *
 * Return: array of string
 */
char **break_line(char *line)
{
	size_t bufsize = 64, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("ERROR");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\n\r");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
			token = strtok(NULL, " \t\n\r");
	}
	tokens[position] = NULL;

	if (tokens[0] != NULL)
	{
		if (strcmp(tokens[0], "exit") == 0)
			exit(0);
	}

	return (tokens);
}
