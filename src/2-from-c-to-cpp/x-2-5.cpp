#include <iostream>
#include <cassert>

const double divide(const double a, const double b)
{
  assert(b != 0);
  return (a / b);
}

int main(int argc, char *argv[], char *envp[])
{
  std::cout << divide(1, 2) << std::endl;
  std::cout << divide(2, 1) << std::endl;
  std::cout << divide(9, 0) << std::endl;

  return 0;
}

