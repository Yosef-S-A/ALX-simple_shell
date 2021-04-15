#include "shell.h"

/**
 * _path - find the path of the command
 * @text: accepts the splitted string
 * @env: accepts the splitted env string
 *
 * Return: returns the path of the command to be executed
 */

char *_path(char *text, char **env)
{
	char *path = NULL, *dir_tmp = NULL;

	dir_tmp = getenv_("PATH", env);
	path = env_variable(dir_tmp, text);
/* printf("path = %s\n", path);*/
	free(dir_tmp);
	return (path);
}
