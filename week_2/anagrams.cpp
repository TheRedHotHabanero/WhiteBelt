#include <iostream>
#include <string>
#include <map>

using std::map;
using std::cout;
using std::cin;
using std::string;

map<char, int> BuildCharCounters(const string& word)
{
  map<char, int> Word;
  for (char a : word) {
    ++Word[a];
  }
  return Word;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    string first_word;
    string second_word;
    cin >> first_word >> second_word;
    if (BuildCharCounters(first_word) == BuildCharCounters(second_word))
    {
      cout << "YES" << '\n';
    }
    else
    {
      cout << "NO" << '\n';
    }
  }

  return 0;
}