#include <exception>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <numeric>
#include <cmath>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::gcd;
using std::ostream;
using std::istream;
using std::ostringstream;
using std::istringstream;
using std::set;
using std::map;
using std::vector;
using std::runtime_error;
using std::invalid_argument;
using std::domain_error;

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
      if (denominator == 0)
        throw invalid_argument("Invalid argument");
      if (denominator < 0)
      {
        denominator *= -1;
        numerator *= -1;
      }
      num = numerator / gcd(numerator, denominator);
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
{
  if (rhs.Numerator() == 0)
    throw domain_error("Division by zero");
  return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

ostream& operator<<(ostream& stream, const Rational& rational)
{
  stream << rational.Numerator() << "/" << rational.Denominator();
  return stream;
}

bool operator>(Rational lhs, Rational rhs)
{ return (lhs.Numerator() / (double)lhs.Denominator()) > double(rhs.Numerator() / (double)rhs.Denominator()); }

bool operator<(Rational lhs, Rational rhs)
{ return (lhs.Numerator() / (double)lhs.Denominator()) < (rhs.Numerator() / (double)rhs.Denominator()); }


istream& operator>>(istream& stream, Rational& rational)
{
  int num;
  int den;
  char sep;
  if ( stream >> num && stream >> sep)
  {
    if(sep != '/')
      return stream;
    if(stream >> den)
      rational = Rational(num, den);
  }
  return stream;
}

Rational calc(const Rational& first, const Rational& second, const char operation)
{
  if (operation == '+')
    return first + second;
  else if (operation == '-')
    return first - second;
  else if (operation == '*')
    return first * second;
  else if (operation == '/')
    return first / second;
  else
  {
    throw invalid_argument("Invalid operation");
    return Rational{0, 0};
  }
}


int main()
{
  Rational first;
  Rational second;
  char operation;
  try
  {
    cin >> first >> operation >> second;
    cout << calc(first, second, operation) << endl;
  }
  catch(const std::exception& e)
  {
    cout << e.what() << endl;
  }
}