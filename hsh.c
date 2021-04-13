#include "shell.h"

char *getenv_(char *name, char **env)
{
  char *token;
  int x = 0;
  char *tmp, *str;

  while (env[x])
    {
      tmp = strdup(env[x]);
      token = strtok(tmp, "=");
      if (strcmp(name, token) == 0)
	{
	  token = strtok(NULL, "=");
	  str = strdup(token);
	  free(tmp);
	  return (str);
	}
      free(tmp);
      x++;
    }
  return (NULL);
}

char *_strcat(char *dest, char *src)
{
  int i, j;

  i = 0;
  while (dest[i] != '\0')
    {
      i++;
    }
  dest[i++] = '/';
  j = 0;
  while ((dest[i++] = src[j++]) != '\0')
    {
    }
  dest[i] = '\0';
  return (dest);
}

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
      printf("path = %s\n", path);
      if (stat(path, &stark) == 0 && stark.st_mode & S_IXUSR)
	return (path);
      token = strtok(NULL, ":");
      free(path);
    }
  return (NULL);
}


char *_path(char *text, char **env)
{
  char *path = NULL, *dir_tmp = NULL;

  dir_tmp = getenv_("PATH", env);
  path = env_variable(dir_tmp, text);
  printf("path = %s\n", path);
  free(dir_tmp);
  return (path);
}

char **break_line(char *line)
{
  size_t bufsize = 64, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
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
      token = strtok(NULL, " \t\n\r" );
    }
  tokens[position] = NULL;
  return (tokens);
}

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)),
         char **environment)
{

  char *program = NULL;
  char *line = NULL;
  size_t len = 0;
  pid_t pid;
  char **segments;
  int status;

  printf ("Madlorien$");
  getline(&line, &len, stdin);
  segments = break_line(line);
  program = _path(segments[0], environment);
  pid = fork();
  if (pid == 0)
    {
      printf("%s\n",line);
      if( execve(program, segments, environment) == -1)
	perror("");
    }
  else
    waitpid(pid, &status, 0);
  return (0);
}
