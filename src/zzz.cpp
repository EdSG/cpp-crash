#include <iostream>

class Foo
{
  private:

    static unsigned int NextFooId;

    const int foo_id;

  public:

    Foo():foo_id(NextFooId++)
    {
      std::cout << *this << std::endl;
    }

    ~Foo()
    {
      std::cout << "~" << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Foo& f)
    {
      return out << "Foo(" << f.foo_id << "):" << &f;
    }

};

unsigned int Foo::NextFooId = 1;

class Bar : public Foo
{
  private:

    static unsigned int NextBarId;

    const int bar_id;

  public:

    Bar():Foo(),bar_id(NextBarId++)
    {
      std::cout << *this << std::endl;
    }

    ~Bar()
    {
      std::cout << "~" << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Bar& b)
    {
      return out << "Bar(" << b.bar_id << "):" << &b;
    }

};

unsigned int Bar::NextBarId = 1;

int main(int argc, char *argv[], char *envp[])
{
  Foo f1;
  Bar b1;

  return 0;
}

