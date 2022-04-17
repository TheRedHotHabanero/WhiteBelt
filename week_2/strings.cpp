#include <iostream>
#include <set>

int main()
{
  int n;
  std::cin >> n;
  std::set<std::string> seq;
  for (int i = 0; i < n; ++i)
  {
    std::string str;
    std::cin >> str;
    seq.insert(str);
  }
  std::cout << seq.size();
}