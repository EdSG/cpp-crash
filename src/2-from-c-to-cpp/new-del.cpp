#include <iostream>

int main(int argc, char **argv)
{
  int *a = new int;
  std::cout << "int *a = new int : " << a << " " << *a << std::endl;
  delete a;

  int *b = new int[5];
  std::cout << "int *b = new int[5] : " << b << " " << *b << std::endl;
  delete b;
}
