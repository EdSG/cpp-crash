#include <iostream>

class Foo {

  public:

    Foo(void) {
      std::cout << "Foo Constructor 1 Called" << std::endl;
    }

    Foo(int v) {
      std::cout << "Foo Constructor 2 Called v = " << v << std::endl;
    }
};

int main(int argc, char *argv[], char *envp[])
{
  Foo foo_1, foo_2(2);

  return 0;
}

