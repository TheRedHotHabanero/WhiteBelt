#include <iostream>
#include <map>
#include <set>
#include <string>

using std::cin;
using std::cout;
using std::map;
using std::string;
using std::set;

void add(string &word1, string &word2, map<string, set<string>> &sinon)
{
  sinon[word1].insert(end(sinon[word1]), word2);
  sinon[word2].insert(end(sinon[word2]), word1);
}

void count(string &word, map<string, set<string>> &sinon)
{ cout << sinon[word].size() << "\n"; }

bool count(string &cword1, string &cword2, map<string, set<string>> &sinon)
{
  if (sinon.count(cword1) && sinon[cword1].count(cword2) != 0)
    return true;
  else
    return false;
}

int main()
{
  int Q;
  cin >> Q;
  map<string, set<string>> sinon;
  string comand;
  for (int i = Q; i > 0; --i)
  {
    cin >> comand;
    if (comand == "ADD")
    {
      string word1, word2;
      cin >> word1 >> word2;
      add(word1, word2, sinon);
    }
    else if (comand == "COUNT")
    {
      string word;
      cin >> word;
      count(word, sinon);
    }
    else if (comand == "CHECK")
    {
      string cword1, cword2;
      cin >> cword1 >> cword2;
      bool a;
      a = count(cword1, cword2, sinon);
      if (a == 1)
        cout << "YES" << "\n";
      else
        cout << "NO" << "\n";
    }
  }
  return 0;
}