#include <iostream>

int main()
{
  int a, b;
  std::cin >> a >> b;
  if (a == b)
  {std::cout << a;}
  else
  {
    while (a > 0 && b > 0)
    {
      if (a > b)
      {a = a % b;}
      else{b = b % a;}
    }
    std::cout << (a + b);
  }
  return 0;
}