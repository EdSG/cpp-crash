#include <iostream>

class Foo
{

   private:

     int _value;

   public:

    Foo(int value=0):_value(value)
    {
      std::cout << "Foo(" << value << ")" << std::endl;
    }

    Foo(const Foo &f)
    {
      std::cout << "Foo(" << &f << ")" << std::endl;
      _value = f._value;
    }

    Foo operator=(const Foo &f)
    {
      std::cout << "operator=(" << &f << ")" << std::endl;
      return Foo(f._value);
    }

    ~Foo()
    {
      std::cout << "~Foo(" << this << ":" << _value << ")" << std::endl;
    }
};

int main(int argc, char **argv, char **envp)
{
  Foo foo0;
  Foo foo1(1);
  foo1 = foo0;
  Foo foo2(foo1);
}

