#include <iostream>

class Foo
{

  private:

    double _value;

  public:

    Foo(double value) : _value(value) { };

    friend std::ostream& operator<<(std::ostream& output, Foo const &that)
    {
      return output << "Foo(" << that._value << ")";
    }

};

int main(int argc, char *argv[], char *envp[])
{
  Foo foo_1(2);

  std::cout << foo_1;

  return 0;
}


