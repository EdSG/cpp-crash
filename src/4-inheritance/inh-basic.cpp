#include <iostream>

class Foo
{
  private:

    int _value;

    void ClearValue(const int value)
    {
      this->_value = value;
    }

  public:

    Foo(int value=0):_value(value)
    {
    }

    virtual ~Foo()
    {
      std::cout << "~" << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Foo& f)
    {
      return out << "Foo(" << &f << ":" << f._value << ")";
    }

    void ResetValue()
    {
      SetValue(0);
    }

  protected:

    void SetValue(const int value)
    {
      ClearValue(value);
    }

};

class Bar_public: public Foo
{
  private:

    int _balue;

  public:

    Bar_public(int balue=0):_balue(balue),Foo(balue)
    {
    }

    virtual ~Bar_public()
    {
      std::cout << "~Bar_public(" << this << ":" << _balue << ")" << std::endl;
    }

    void Method_Public(const int balue)
    {
      ResetValue();
      SetValue(balue);
      // ClearValue(2); // void Foo::ClearValue(int) is private
    }

};

class Bar_private: private Foo
{
  private:

    int _balue;

  public:

    Bar_private(int balue=0):_balue(balue),Foo(balue)
    {
    }

    virtual ~Bar_private()
    {
      std::cout << "~Bar_private(" << this << ":" << _balue << ")" << std::endl;
    }

    void Method_Private(const int balue)
    {
      ResetValue();
      SetValue(balue);
      // ClearValue(2); // void Foo::ClearValue(int) is private
    }

};

class Bar_protected: protected Foo
{
  private:

    int _balue;

  public:

    Bar_protected(int balue=0):_balue(balue),Foo(balue)
    {
    }

    virtual ~Bar_protected()
    {
      std::cout << "~Bar_protected(" << this << ":" << _balue << ")" << std::endl;
    }

    void Method_Protected(const int balue)
    {
      ResetValue();
      SetValue(balue);
      // ClearValue(2); // void Foo::ClearValue(int) is private
    }

};

int main(int argc, char *argv[], char *envp[])
{
  Foo f;
  Bar_public bpub(1);
  Bar_private bpriv(2);
  Bar_protected bprot(3);

  bpub.ResetValue();
  // bpub.SetValue(1); // void Foo::SetValue(int) is protected
  bpub.Method_Public(10);

  // bpriv.ResetValue(); // void Foo::ResetValue() is inaccessible
  // bpriv.SetValue(2); // void Foo::SetValue(int) is inaccessible
  bpriv.Method_Private(20);

  // bprot.ResetValue(); // void Foo::ResetValue() is inaccessible
  // bprot.SetValue(3); // void Foo::SetValue(int) is protected
  bprot.Method_Protected(30);

  return 0;
}

