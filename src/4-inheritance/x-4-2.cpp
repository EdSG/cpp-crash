#include <iostream>

int foo(int a, int b);

class Foo
{
  private:

    int _value;

  public:

    Foo(int value):_value(value)
    {
      std::cout << *this << std::endl;
    }

    ~Foo()
    {
      std::cout << "~" << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Foo& f)
    {
      return out << "Foo(" << f._value << "):" << &f;
    }

    int foo(int a, int b)
    {
      return (this->_value = ::foo(a, b));
    }

};

int foo(int a, int b)
{
  return a * b;
}

int main(int argc, char *argv[], char *envp[])
{
  Foo f1(1);
  int a = 3;
  int b = 3;

  std::cout << "f1.foo(" << a << "," << b << ") = " << f1.foo(a, b) << std::endl;
  std::cout << f1 << std::endl;

  return 0;
}

