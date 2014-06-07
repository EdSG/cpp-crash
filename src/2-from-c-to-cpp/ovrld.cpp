#include <iostream>

float add(float a, float b)
{
  return a + b;
}

int add(int a, int b)
{
  return a + b;
}

int main(int argc, char *argv[], char *envp[])
{
  std::cout
    << add(0.1f, 0.2f) << std::endl
    << add(1, 2) << std::endl;

  return 0;
}

