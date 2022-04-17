#include <iostream>
#include <map>
#include <string>

using std::string;
using std::map;

struct Fullname
{
  string name;
  string surname;
};

class Person
{
  private:
    map<int, Fullname> Year;

  public:
    void ChangeFirstName(int year, const string &first_name)
    {
      if (Year.count(year) == 0)
        Year[year].surname = "";
      Year[year].name = first_name;
    }
    void ChangeLastName(int year, const string &last_name)
    {
      if (Year.count(year) == 0)
        Year[year].surname = "";
      Year[year].surname = last_name;
    }
    string GetFullName(int year)
    {
      for (const auto &i : Year)
      {
        if (year < i.first)
          return "Incognito";
        break;
      }
      string n = "";
      string s = "";

      for (const auto &i : Year)
      {
        if (i.first <= year && i.second.surname != "")
          s = i.second.surname;
        if (i.first <= year && i.second.name != "")
          n = i.second.name;
      }
      if (n == "")
        return s + " with unknown first name";
      else if (s == "")
        return n + " with unknown last name";
      else
        return n + " " + s;
    }
};

int main()
{

}