#include <iostream>

class Foo
{
  private:

    int _value;

  protected:

    int GetValue() const
    {
      return _value;
    }

    void SetValue(const int value)
    {
      _value = value;
    }

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

    virtual void method1(void) = 0;
};

class Bar1: public Foo
{
  public:

    Bar1(int _balue):Foo(_balue)
    {
      method1();
    }

    void method1(void)
    {
      SetValue(this->GetValue() + 1);
    }

};

class Bar2: public Foo
{

  public:

    Bar2(int _balue):Foo(_balue)
    {
      method1();
    }

    void method1(void)
    {
      SetValue(this->GetValue() * 2);
    }

};

int main(int argc, char** argv, char** envp)
{
  // Foo f1(0); // cannot declare variable to be of abstract type
  Bar1 b1(1);
  Bar2 b2(2);

  return 0;
}
