#include <iostream>
#include <map>
#include <set>
#include <string>

using std::map;
using std::set;
using std::string;
using std::cin;
using std::cout;

int main()
{
  set<string> bus_stops;
  map<set<string>, int> m;
  int Q;
  int count_stop = 0;
  int number_m = 0;

  string stop;
  cin >> Q;
  for (int i = 0; i < Q; ++i)
  {
    cin >> count_stop;
    for (count_stop; count_stop > 0; --count_stop)
    {
      cin >> stop;
      bus_stops.insert(stop);
    }

    if (!m.count(bus_stops))
    {
      m[bus_stops] = ++number_m;
      cout << "New bus " << number_m << "\n";
    }
    else
      cout << "Already exists for " << m[bus_stops] << "\n";
    bus_stops.clear();
  }
  return 0;
}