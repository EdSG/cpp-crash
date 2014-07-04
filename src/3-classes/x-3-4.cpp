#include <iostream>

class Foo
{
  private:

    int _value;

  public:

    Foo(int value=0):_value(value)
    {
    }

    friend std::istream& operator>>(std::istream& in, Foo& f)
    {
      return in >> f._value;
    }

    friend std::ostream& operator<<(std::ostream& out, const Foo& f)
    {
      return out << "Foo(" << &f << ":" << f._value << ")";
    }

};

int main(int argc, char *argv[], char *envp[])
{
  Foo f;

  std::cout << f << std::endl;

  std::cout << "Provide Foo with a new value: ";
  std::cin >> f;

  std::cout << f << std::endl;

  return 0;
}

