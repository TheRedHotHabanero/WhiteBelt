

#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::map;
using std::string;
using std::vector;

int main()
{
  int Q, i;
  string stop;
  map<vector<string>, int> bs;
  cin >> Q;
  for (Q; Q > 0; Q--)
  {
    vector<string> v;
    cin >> i;
    for (int z = 0; z < i; ++z)
    {
      cin >> stop;
      v.push_back(stop);
    }
    if (bs.count(v))
      cout << "Already exists for " << bs[v] << "\n";
    else
    {
      bs[v];
      int r = bs.size();
      bs[v] = r;
      cout << "New bus " << bs[v] << "\n";
    }
  }
  return 0;
}