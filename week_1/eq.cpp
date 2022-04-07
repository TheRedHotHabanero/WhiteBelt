#include <iostream>
#include <cmath>

int main()
{
  double a;
  double b;
  double c;

  std::cin >> a >> b >> c;

  if (a != 0)
  {
    double D = b * b - 4 * a * c;
    if (D > 0)
    {
      double x1 = ((-1) * b + sqrt(D)) / (2 * a);
      double x2 = ((-1) * b - sqrt(D)) / (2 * a);
      std::cout << x1 << " " << x2;
      return 0;
    }
    else if (D == 0)
    {
      double x = (-1) * b / (2 * a);
      std::cout << x;
      return 0;
    }
  }
  else if (a == 0)
  {
    if (b != 0)
    {
      double x = (-1) * c / b;
      std::cout << x;
      return 0;
    }
    else if (b == 0)
    {
      return 0;
    }
  }
  return 0;
}