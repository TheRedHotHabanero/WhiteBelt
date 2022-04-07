#include <iostream>
using std::string;

int main()
{
  string mazafaka;
  std::cin >> mazafaka;
  int counter = 0;
  for (int i = 0; i < mazafaka.size(); ++i)
  {
    if (mazafaka[i] == 'f')
    {
      counter += 1;
      if (counter == 2)
      {std::cout << i; }
    }
  }
  if (counter == 0)
  {std::cout << -2; }
  if (counter == 1)
  {std::cout << -1; }
  return 0;
}