#include <iostream>
#include <numeric>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::gcd;

class Rational
{
  private:
    int num;
    int den;

  public:
    Rational()
    {
      num = 0;
      den = 1;
    }

    Rational(int numerator, int denominator)
    {
      if (denominator < 0)
      {
        denominator *= -1;
        numerator *= -1;
      }
      num = numerator / std::gcd(numerator, denominator);
      den = denominator / gcd(numerator, denominator);
    }

    int Numerator() const
    { return num; }

    int Denominator() const
    { return den; }
};

Rational operator+(const Rational& lhs, const Rational& rhs)
{ return Rational(lhs.Numerator() * rhs.Denominator() +
  rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator()); }

Rational operator-(const Rational& lhs, const Rational& rhs)
{ return Rational(lhs.Numerator() * rhs.Denominator() -
  rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator()); }

bool operator==(const Rational& lhs, const Rational& rhs)
{ return(lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()); }

Rational operator*(const Rational& lhs, const Rational& rhs)
{ return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()); }

Rational operator/(const Rational& lhs, const Rational& rhs)
{ return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator()); }

int main()
{
  {
    Rational a(2, 3);
    Rational b(4, 3);
    Rational c = a * b;
    bool equal = c == Rational(8, 9);
    if (!equal)
    {
      cout << "2/3 * 4/3 != 8/9" << endl;
      return 1;
    }
  }

  {
    Rational a(5, 4);
    Rational b(15, 8);
    Rational c = a / b;
    bool equal = c == Rational(2, 3);
    if (!equal)
    {
      cout << "5/4 / 15/8 != 2/3" << endl;
      return 2;
    }
  }
  cout << "OK" << endl;
  return 0;
}