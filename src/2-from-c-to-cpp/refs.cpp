#include <stdlib.h>
#include <iostream>

int main(int argc, char** argv)
{
  int x;
  int& foo = x;

  foo = 42;

  std::cout << x << std::endl;

  return EXIT_SUCCESS;
}
