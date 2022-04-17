#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using std::string;
using std::map;
using std::set;
using std::cin;
using std::cout;
using std::endl;
using std::iterator;

// Напишите функцию BuildMapValuesSet,
// принимающую на вход словарь map<int, string> и
// возвращающую множество значений этого словаря:
set<string> BuildMapValuesSet(const map<int, string>& m)
{
  set<string> seq;
  int s = m.size();
  map<int,string>::const_iterator it = m.begin();
  for (int i = 0; i < s; ++i)
  {
    seq.insert(it->second);
    it++;
  }
  return seq;
}

/*
int main()
{
  set<string> values = BuildMapValuesSet({
      {1, "odd"},
      {2, "even"},
      {3, "odd"},
      {4, "even"},
      {5, "odd"}
  });

  for (const string& value : values) {
    cout << value << endl;
    // even
    // odd
  }
  return 0;
}
*/