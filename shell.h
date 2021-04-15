#ifndef _SHELL_H_
#define _SHELL_H_

/*
 * File: shell.h
 * Auth: Yosef Samuel and Fortune Mwagambo
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

char *getenv_(char *name, char **env);
char *env_variable(char *dir_tmp, char *text);
char *_strcat(char *dest, char *src);
char *_path(char *text, char **env);
char **break_line(char *line);

#endif /* _SHELL_H_ */
