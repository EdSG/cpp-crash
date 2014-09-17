#include <iostream>
#include <cmath>

class Real
{
  protected:

    const double _value = 0.0;

    virtual const double GetValue() const
    {
      return this->_value;
    }

  public:

    Real(double value = 0.0):_value(value)
    {
      std::cout << *this << std::endl;
    }

    Real(const Real& r):Real(r._value)
    {
    }

    ~Real()
    {
      std::cout << "~" << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Real& r)
    {
      return out << "Real(" << r._value << "):" << &r;
    }

    virtual Real operator+(const Real& r2)
    {
      return Real(this->_value + r2._value);
    }

    virtual Real operator-(const Real& r2)
    {
      return Real(this->_value - r2._value);
    }

    virtual Real operator*(const Real& r2)
    {
      return Real(this->_value * r2._value);
    }

    virtual Real operator/(const Real& r2)
    {
      return Real(this->_value / r2._value);
    }

};

class Integer : public Real
{
  protected:

    const long _value = 0L;

  public:

    Integer(long value = 0):_value(value),Real(round(value))
    {
      std::cout << *this << std::endl;
    }

    Integer(const Integer& i):Integer(i._value)
    {
    }

    Integer(const Real& r):Real(r),_value(long(floor(this->GetValue())))
    {
    }

    ~Integer()
    {
      std::cout << "~" << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Integer& i)
    {
      return out << "Integer(" << i._value << "):" << &i;
    }

};

int main(int argc, char *argv[], char *envp[])
{
  Real r0;
  Real r1(1.1);
  Real r2(20.02);
  Real r3(300.003);

  std::cout << std::endl << "Real constructors: Done." << std::endl << std::endl;

  Real r4 = r1 + r2;
  Real r5 = r1 - r2;
  Real r6 = r3 * r2;
  Real r7 = r3 / r2;

  std::cout << std::endl << "Real operations: Done." << std::endl << std::endl;

  Integer i0;
  Integer i1(1);
  Integer i2(20);
  Integer i3(300);

  std::cout << std::endl << "Integer constructors: Done." << std::endl << std::endl;

  Integer i4 = i1 + i2;
  Integer i5 = i1 - i2;
  Integer i6 = i3 * i2;
  Integer i7 = i3 / i2;

  std::cout << std::endl << "Integer operations: Done." << std::endl << std::endl;

  Real r8 = r6 + i6;
  Integer i8 = i7 + r7;

  std::cout << std::endl << "Mixed operations: Done." << std::endl << std::endl;

  return 0;
}

