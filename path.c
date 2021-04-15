#include "shell.h"

char *_path(char *text, char **env)
{
  char *path = NULL, *dir_tmp = NULL;

  dir_tmp = getenv_("PATH", env);
  path = env_variable(dir_tmp, text);
  /* printf("path = %s\n", path);*/
  free(dir_tmp);
  return (path);
}
