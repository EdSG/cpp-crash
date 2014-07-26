#include <iostream>

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

    int GetValue()
    {
      return this->_value;
    }

};

class Bar: public Foo
{
  public:

    Bar(int value):Foo(value)
    {
      std::cout << *this << std::endl;
    }

    ~Bar()
    {
      std::cout << "~" << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Bar& b)
    {
      return out << "Bar(" << ((Foo&)b).GetValue() << "):" << &b;
    }
};

int main(int argc, char *argv[], char *envp[])
{
  Foo foo1(1);
  Bar bar1(2);

  return 0;
}

