#include "shell.h"

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
