#include <iostream>
#include <vector>
using std::string;

void MoveStrings(std::vector<string>& source, std::vector<string>& destination)
{
  for (int i = 0; i < source.size(); ++i)
  {
    destination.push_back(source[i]);
  }
  source.clear();
}

int main()
{
  std::vector<string> source = {"a", "b", "c"};
  std::vector<string> destination = {"z"};
  MoveStrings(source, destination);
  // source должен оказаться пустым
  // destination должен содержать строки "z", "a", "b", "c" именно в таком порядке
  for (int i = 0; i < destination.size(); ++i)
  {std::cout << destination[i] << " ";}
  return 0;
}