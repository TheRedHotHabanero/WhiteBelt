#include <iostream>
#include <map>
#include <string>

int main()
{
  std::map<int, std::string> m = {{1, "odd"}, {2, "even"}, {1, "one"}};
  m[2] = "two";
  m.erase(1);
  m[3] = "three";
  m.erase(4);
  m[5] = "five";
  std::cout << m.size();
  return 0;
}