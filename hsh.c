#include "shell.h"

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)),
         char **environment)
{
  while (1)
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
	  if(execve(program, segments, environment) == -1)
	    perror("");
	}
      else
	waitpid(pid, &status, 0);
    }
  return (0);
}
