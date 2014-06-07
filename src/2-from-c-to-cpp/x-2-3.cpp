#include <iostream>

void swap(int &a, int &b)
{
  int tmp;

  tmp = a;
  a = b;
  b = tmp;

  return;
}

void swap(int* &a, int* &b)
{
  int* tmp;

  tmp = a;
  a = b;
  b = tmp;

  return;
}

int main(int argc, char *argv[], char *envp[])
{
  int x = 1;
  int y = 9;

  int * p1 = &x;
  int * p2 = &y;

  std::cout << x << '\t' << y << std::endl;
  swap(x, y);
  std::cout << x << '\t' << y << std::endl;

  std::cout << p1 << '\t' << p2 << std::endl;
  swap(p1, p2);
  std::cout << p1 << '\t' << p2 << std::endl;

  return 0;
}

