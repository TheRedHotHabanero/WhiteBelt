#include <iostream>
#include <vector>
using std::vector;

void Reverse(vector<int>& v)
{
  int tmp;
  for (int i = 0; i < (v.size() / 2); ++i)
  {
    tmp = v[i];
    v[i] = v[v.size() - i - 1];
    v[v.size() - i - 1] = tmp;
  }
}

int main()
{
  vector<int> numbers = {1, 5, 3, 4, 2};
  Reverse(numbers);
  // numbers должен оказаться равен {2, 4, 3, 5, 1}
  for (int i = 0; i < numbers.size(); ++i)
  {std::cout << numbers[i] << " ";}
  return 0;
}