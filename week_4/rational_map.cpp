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
  {
    const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
    if (rs.size() != 3)
    {
      cout << "Wrong amount of items in the set" << endl;
      return 1;
    }

    vector<Rational> v;
    for (auto x : rs)
    { v.push_back(x); }

    if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}})
    {
      cout << "Rationals comparison works incorrectly" << endl;
      return 2;
    }
  }

  {
    map<Rational, int> count;
    ++count[{1, 2}];
    ++count[{1, 2}];

    ++count[{2, 3}];

    if (count.size() != 2)
    {
      cout << "Wrong amount of items in the map" << endl;
      return 3;
    }
  }

  cout << "OK" << endl;
  return 0;
}