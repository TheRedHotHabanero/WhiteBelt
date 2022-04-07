#include <iostream>
#include <vector>
using std::vector;

vector<int> Reversed(const vector<int>& v)
{
  vector<int> new_v;
  for (int i = 0; i < v.size(); ++i)
  {
    new_v.push_back(v[v.size() - i - 1]);
  }
  return new_v;
}

int main()
{
  vector<int> numbers = {1, 5, 3, 4, 2};
  Reversed(numbers);
  // numbers должен оказаться равен {2, 4, 3, 5, 1}
  for (int i = 0; i < numbers.size(); ++i)
  {std::cout << numbers[i] << " ";}
  return 0;
}