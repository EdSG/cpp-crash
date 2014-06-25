#include <iostream>

class Foo
{

  private:

    int _value;

  public:

    Foo(int value) : _value(value)
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
  Foo foo(0);

  return 0;
}


