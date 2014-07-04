#include <iostream>

class Foo
{
  private:

    int _value;

  public:

    Foo(int value=0):_value(value)
    {
    }

    Foo& method1(const int x)
    {
      this->_value = this->_value + x;
      return *this;
    }

    Foo& method2(const int y)
    {
      this->_value = this->_value * y;
      return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Foo& f)
    {
      return out << "Foo(" << &f << ":" << f._value << ")";
    }

};

int main(int argc, char *argv[], char *envp[])
{
  Foo f0;

  std::cout << f0 << std::endl;

  std::cout << f0.method1(1).method2(2) << std::endl;

  return 0;
}

