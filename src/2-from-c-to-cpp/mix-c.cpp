#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#ifdef __cplusplus
}
#endif

int main(int argc, char *argv[], char *envp[])
{
  printf("printf(\"%s\")","printf(\"%s\")");
  std::cout << std::endl;

  return 0;
}

