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
