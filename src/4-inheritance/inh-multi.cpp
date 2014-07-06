#include <iostream>

class Foo
{
  protected:

    int _value;

  public:

    Foo(int value=0):_value(value) { }

    virtual ~Foo()
    {
      std::cout << "~" << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Foo& f)
    {
      return out << "Foo(" << &f << ":" << f._value << ")";
    }

};

class Bar1: public Foo
{
  public:

    Bar1(int _balue):Foo(_balue) { }

    friend std::ostream& operator<<(std::ostream& out, const Bar1& b1)
    {
      return out << "Bar1(" << &b1 << ":" << b1._value << ")";
    }

};

class Bar2: public Foo
{

  public:

    Bar2(int _balue):Foo(_balue) { }

    friend std::ostream& operator<<(std::ostream& out, const Bar2& b2)
    {
      return out << "Bar2(" << &b2 << ":" << b2._value << ")";
    }

};

class Bar3: public Bar1, public Bar2
{

  public:

    Bar3(int _balue):Bar1(_balue + 1),Bar2(_balue * 2) { }

    friend std::ostream& operator<<(std::ostream& out, const Bar3& b3)
    {
      return out << "Bar3(" << &b3 << ":" << b3.Bar1::_value << ":" << b3.Bar2::_value << ")";
    }

};

int main(int argc, char** argv, char** envp)
{
  Bar3 b1(1);
  Bar3 b2(2);

  return 0;
}
