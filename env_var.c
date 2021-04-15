#include "shell.h"

/**
 * env_variable - matches command with env variable
 * @dir_tmp: dir_tmp
 * @text: text
 *
 * Return: char
 */
char *env_variable(char *dir_tmp, char *text)
{

	char *path = NULL, *token = NULL;
	struct stat stark;
/*int i;*/
	token = strtok(dir_tmp, ":");
	while (token)
	{
		path = malloc(strlen(token) + 1 + strlen(text) + 2);
		strcpy(path, token);
		_strcat(path, text);
/* printf("path = %s\n", path);*/
		if (stat(path, &stark) == 0 && stark.st_mode & S_IXUSR)
			return (path);
		token = strtok(NULL, ":");
		free(path)
			}
	return (NULL);
}
