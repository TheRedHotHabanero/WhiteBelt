#include <iostream>
#include <cmath>

int main()
{
  int a;
  int b;
  std::cin >> a >> b;
  if (b != 0)
  {std::cout << (a / b); }
  else
  {std::cout << "Impossible"; }
  return 0;
}