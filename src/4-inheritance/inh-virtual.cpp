#include <iostream>

class Foo
{
  private:

    int _value;

  protected:

    int GetValue()
    {
      return _value;
    }

  public:

    Foo(const int value=0):_value(value) { }

    void Method1(void)
    {
      std::cout << "Foo(" << this << ":" << GetValue() << ")::Method1()" << std::endl;
    }

    virtual void Method2(void)
    {
      std::cout << "Foo(" << this << ":" << GetValue() << ")::Method2()" << std::endl;
    }

};

class Bar: public Foo
{
  public:

    Bar(const int value=0):Foo(value) { }

    void Method1(void)
    {
      std::cout << "Bar(" << this << ":" << GetValue() << ")::Method1()" << std::endl;
    }

    virtual void Method2(void)
    {
      std::cout << "Bar(" << this << ":" << GetValue() << ")::Method2()" << std::endl;
    }

};

int main(int argc, char** argv, char** envp)
{
  Foo f1(1);
  Bar b1(2);
  Foo* f = &f1;
  Foo* b = &b1;

  f1.Method1();
  f->Method1();
  f1.Method2();
  f->Method2();

  b1.Method1();
  b->Method1();
  b1.Method2();
  b->Method2();

  return 0;
}
