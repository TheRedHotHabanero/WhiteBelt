
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main()
{
  int N;
  int num;
  vector<int> v;

  cin >> N;
  for (N; N > 0; --N)
  {
    cin >> num;
    v.push_back(num);
  }
  sort(begin(v), end(v), [](const int &x, const int &y) { return abs(x) < abs(y); });
  for (const auto &i : v)
  { cout << i << " "; }
  return 0;
}