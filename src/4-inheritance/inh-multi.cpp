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

    virtual ~Bar1()
    {
      std::cout << "~" << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Bar1& b1)
    {
      return out << "Bar1(" << &b1 << ":" << b1._value << ")";
    }

};

class Bar2: public Foo
{

  public:

    Bar2(int _balue):Foo(_balue) { }

    virtual ~Bar2()
    {
      std::cout << "~" << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Bar2& b2)
    {
      return out << "Bar2(" << &b2 << ":" << b2._value << ")";
    }

};

class Bar3: public Bar1, public Bar2
{

  public:

    Bar3(int _balue):Bar1(_balue),Bar2(_balue * 2) { }

    virtual ~Bar3()
    {
      std::cout << "~" << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Bar3& b3)
    {
      return out << "Bar3(" << &b3 << ":" << b3.Bar1::_value << ":" << b3.Bar2::_value << ")";
    }

};

int main(int argc, char** argv, char** envp)
{
  Bar3 b3_1(1);
  Bar3 b3_2(2);

  Foo* f1 = dynamic_cast<Bar1*>(&b3_1);
  Foo* f2 = dynamic_cast<Bar2*>(&b3_2);
  Bar1* b1_1 = &b3_1;
  Bar1* b1_2 = &b3_2;
  Bar2* b2_1 = &b3_1;
  Bar2* b2_2 = &b3_2;

  std::cout << "b3_1 : " << b3_1 << std::endl;
  std::cout << "b3_2 : " << b3_2 << std::endl;
  std::cout << "f1 : " << *f1 << std::endl;
  std::cout << "f2 : " << *f2 << std::endl;
  std::cout << "b1_1 : " << *b1_1 << std::endl;
  std::cout << "b1_2 : " << *b1_2 << std::endl;
  std::cout << "b2_1 : " << *b2_1 << std::endl;
  std::cout << "b2_2 : " << *b2_2 << std::endl;

  return 0;
}
