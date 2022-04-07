#include <iostream>
using std::string;

bool IsPalindrom(string mazafaka)
{
  int length = mazafaka.size();
  bool isPal = true;
  for (int i = 0; i < (length / 2); ++i)
  {
    if (mazafaka[i] != mazafaka[length - i - 1])
    {
      isPal = false;
      return isPal;
    }
  }
  return isPal;
}

int main()
{
  string mazafaka;
  std::cin >> mazafaka;
  std::cout << IsPalindrom(mazafaka);
  return 0;
}