#include <iostream>

void UpdateIfGreater(const int first, int& second)
{
  int tmp;
  if (first > second)
  {
    //tmp = second;
    second = first; //second -> first
    //first = tmp; // first -> second
  }
}

int main()
{
  int a = 4;
  int b = 2;
  UpdateIfGreater(4, b);
  std::cout << b;
// b должно стать равно 4
  return 0;
}