#include <iostream>
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

ostream& operator<<(ostream& stream, const Rational& rational)
{
  stream << rational.Numerator() << "/" << rational.Denominator();
  return stream;
}

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
  {
    ostringstream output;
    output << Rational(-6, 8);
    if (output.str() != "-3/4")
    {
      cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
      return 1;
    }
  }

  {
    istringstream input("5/7");
    Rational r;
    input >> r;
    bool equal = r == Rational(5, 7);
    if (!equal)
    {
      cout << "5/7 is incorrectly read as " << r << endl;
      return 2;
    }
  }

  {
    istringstream input("");
    Rational r;
    bool correct = !(input >> r);
    if (!correct)
    {
      cout << "Read from empty stream works incorrectly" << endl;
      return 3;
    }
  }

  {
    istringstream input("5/7 10/8");
    Rational r1, r2;
    input >> r1 >> r2;
    bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct)
    {
      cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
      return 4;
    }

    input >> r1;
    input >> r2;
    correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct)
    {
      cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
      return 5;
    }
  }

  {
    istringstream input1("1*2"), input2("1/"), input3("/4");
    Rational r1, r2, r3;
    input1 >> r1;
    input2 >> r2;
    input3 >> r3;
    bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
    if (!correct)
    {
      cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
           << r1 << " " << r2 << " " << r3 << endl;
      return 6;
    }
  }

  {
    istringstream input("2/4/6/8");
    Rational r1;
    input >> r1;
    bool correct = r1 == Rational(1, 2);
    if (!correct)
    {
      cout << "Multiple-slashed number sequence value read incorrectly: " << r1 << endl;
      return 7;
    }
  }
  cout << "OK" << endl;
  return 0;
}