#include <iostream>

class Foo
{
  private:

    int _value;

  public:

    Foo(int value=0):_value(value)
    {
    }

    virtual ~Foo()
    {
      std::cout << std::endl << "~Foo()" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Foo& f)
    {
      return out << "Foo(" << &f << ":" << f._value << ")";
    }

  protected:

    void SetValue(const int value)
    {
      this->_value = value;
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
      std::cout << std::endl << "~Bar_public()" << std::endl;
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
      std::cout << std::endl << "~Bar_private()" << std::endl;
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
      std::cout << std::endl << "~Bar_protected()" << std::endl;
    }

};

int main(int argc, char *argv[], char *envp[])
{
  Foo f;
  Bar_public bpub;
  Bar_private bpriv;
  Bar_private bprot;

  return 0;
}

