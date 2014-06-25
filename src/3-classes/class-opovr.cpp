#include <iostream>

class Foo
{

  private:

    int _value;

  public:

    Foo(int value) : _value(value)
    {
      std::cout << "Foo Constructor Called " << _value << std::endl;
    }

    Foo operator+(const Foo &other)
    {
      return Foo(_value + other._value);
    }

    Foo operator*(const Foo &other)
    {
      return Foo(_value * other._value);
    }

    ~Foo()
    {
      std::cout << "Foo Destructor Called " << _value << std::endl;
    }

};

int main(int argc, char *argv[], char *envp[])
{
  Foo foo_1(2), foo_2(5);

  Foo foo_3 = foo_1 + foo_2;

  Foo foo_4 = foo_1 * foo_2;

  return 0;
}


