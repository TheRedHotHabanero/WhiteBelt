#include <iostream>

int Factorial(int num)
{
  int res = 1;
  if (num < 0)
  {return 1;}
  else
  {
    for (int i = 1; i <= num; ++i)
    {
      res *= i;
    }
    return res;
  }
}

int main()
{
  int x;
  std::cin >> x;
  std::cout << Factorial(x);
  return 0;
}