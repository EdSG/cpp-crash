#include <iostream>

#define BAD_SQUARE(x) x*x
#define SQUARE(x) (x)*(x)

const int Two = 2;

int inline square(int x)
{
  return x*x;
}

int main(int argc, char *argv[], char *envp[])
{
  std::cout
    << BAD_SQUARE(3 + 3) << std::endl
    << SQUARE(Two + 1) << std::endl
    << square(Two + 2) << std::endl;

  return 0;
}

