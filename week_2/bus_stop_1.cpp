#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::map;
using std::vector;
using std::string;

void all_buses(const map<string, vector<string>> &bsmap)
{
  if (bsmap.size() == 0)
    cout << "No buses" << "\n";
  else
  {
    for (const auto &i : bsmap)
    {
      cout << "Bus " << i.first << ":";
      for (const auto &d : i.second)
      { cout << " " << d; }
      cout << "\n";
    }
  }
}
void BusforStop(const string &s, const map<string, vector<string>> &bsmap,
                const vector<string> &busm)
{
  int k = 0;
  vector<string> v;
  for (const auto &i : bsmap)
  {
    for (const auto &n : i.second)
    {
      if (n == s)
      {
        v.push_back(i.first);
        k++;
      }
    }
  }
  if (k > 0)
  {
    for (const auto &w : busm)
    {
      for (auto z : v)
      {
        if (z == w)
          cout << w << " ";
      }
    }
  }
  else if (k == 0)
    cout << "No stop";
  cout << "\n";
}
void Stopforbus(const string &s, const map<string, vector<string>> &bsmap,
                const vector<string> &busm)
{
  int l = 0;
  for (auto i : bsmap)
  {
    if (i.first == s)
    {
      for (auto m : i.second)
      {
        cout << "Stop " << m << ":";
        int l2 = 0;
        vector<string> v;
        for (auto r : bsmap)
        {
          for (auto n : r.second)
          {
            if (n == m && r.first != s)
            {
              v.push_back(r.first);
              l2++;
            }
          }
        }
        if (l2 == 0)
          cout << " no interchange";
        else if (l2 > 0)
        {
          for (const auto &w : busm)
          {
            for (auto z : v)
            {
              if (z == w)
                cout << " " << w;
            }
          }
        }
        cout << "\n";
      }
      l++;
    }
  }
  if (l == 0)
    cout << "No bus" << "\n";
}
int main()
{
  int Q;
  cin >> Q;
  map<string, vector<string>> bsmap;
  vector<string> busm;
  for (Q; Q > 0; Q--)
  {
    string comand, bus, stop;
    cin >> comand;
    if (comand == "NEW_BUS")
    {
      int sc;
      cin >> bus >> sc;
      busm.push_back(bus);
      for (sc; sc > 0; sc--)
      {
        cin >> stop;
        bsmap[bus].push_back(stop);
      }
    }
    else if (comand == "BUSES_FOR_STOP")
    {
      cin >> stop;
      BusforStop(stop, bsmap, busm);
    }
    else if (comand == "STOPS_FOR_BUS")
    {
      cin >> bus;
      Stopforbus(bus, bsmap, busm);
    }
    else if (comand == "ALL_BUSES")
      all_buses(bsmap);
  }
  return 0;
}