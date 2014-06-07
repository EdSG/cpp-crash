#include <iostream>

int add(int a, int b)
{
  return (a + b);
}

int add(int a, int b, int c = 0)
{
  return (a + b + c);
}

int main(int argc, char *argv[], char *envp[])
{
  // std::cout << add(1, 2) << std::endl;

  std::cout << add(1, 2, 3) << std::endl;

  return 0;
}

