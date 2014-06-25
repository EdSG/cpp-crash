#include <iostream>

class Foo {

  public:

    Foo(void)
    {
      std::cout << "Foo Constructor Called" << std::endl;
    };

    ~Foo()
    {
      std::cout << "Foo Destructor Called" << std::endl;
    };

};

int main(int argc, char *argv[], char *envp[])
{
  Foo foo;

  return 0;
}

