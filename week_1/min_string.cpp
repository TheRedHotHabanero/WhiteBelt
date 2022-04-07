#include <iostream>
using std::string;

int main()
{
  string first;
  string second;
  string third;
  std::cin >> first >> second >> third;
  if (first <= second && first <= third)
  {std::cout << first;}
  else if (second <= first && second <= third)
  {std::cout << second; }
  else if (third <= first && third <= second)
  {std::cout << third; }

  return 0;
}