#include <iostream>

template <typename T>
class Operator
{
  private:
    const T _value;

    const std::string _desc;

  public:

    Operator(const T value, std::string desc):_value(value),_desc(desc)
    {
      std::cout << *this << std::endl;
    }

    ~Operator()
    {
      std::cout << "~" << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Operator& op)
    {
      return out << "Operator(" << op._desc << ":" << op._value << "):" << &op;
    }

    T operator()(const T a)
    {
      return (a + this->_value);
    }

};

template <class T>
class Executor
{
  private:

    Operator<T>& _op;

  public:

    Executor(Operator<T>& op):_op(op)
    {
      std::cout << *this << std::endl;
    }

    ~Executor()
    {
      std::cout << "~" << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Executor& e)
    {
      return out << "Executor(" << e._op << "):" << &e;
    }

    T PerformOperation(const T a)
    {
      return _op(a);
    }

};

int main(int argc, char *argv[], char *envp[])
{
  Operator<int> op1(1, "Op1");
  Executor<int> exec1(op1);

  std::cout << "PerformOperation() = " << exec1.PerformOperation(1) << std::endl;

  return 0;
}

