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
        throw invalid_argument("invalid_argument");
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
    throw domain_error("domain_error");
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


int main()
{
  try
  {
    Rational r(1, 0);
    cout << "Doesn't throw in case of zero denominator" << endl;
    return 1;
  }
  catch (invalid_argument &) {}

  try
  {
    auto x = Rational(1, 2) / Rational(0, 1);
    cout << "Doesn't throw in case of division by zero" << endl;
    return 2;
  }
  catch (domain_error &) {}

  cout << "OK" << endl;
  return 0;
}