#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::tolower;

string lower(const string &s)
{
  string result;
  for (auto i : s)
  {
    result += tolower(i);
  }
  return result;
}

bool my_sort(string x, string y)
{ return lower(x) < lower(y); }

int main()
{
  int n;
  string str;
  vector<string> v;
  cin >> n;
  for (n; n > 0; --n)
  {
    cin >> str;
    v.push_back(str);
  }
  sort(begin(v), end(v), my_sort);
  for (const auto &i : v)
  { cout << i << " "; }
  return 0;
}