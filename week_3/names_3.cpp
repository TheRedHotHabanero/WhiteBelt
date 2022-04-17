#include <iostream>
#include <map>
#include <vector>
#include <string>

using std::string;
using std::map;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

struct FullName
{
  string name;
  string surname;
};

class Person
{
  private:
    map<int, FullName> Year;
    int birth_year = 0;

  public:

    Person (const string& first_name, const string& last_name, int year)
    {
      Year[year] = { first_name, last_name };
      birth_year = year;
      for (auto& i : Year)
      { if (i.first < year) Year.erase(i.first); }
    }

    void ChangeFirstName(int year, const string &first_name)
    {
      if (year < birth_year)
        return;
      if (Year.count(year) == 0)
        Year[year].surname = "";
      Year[year].name = first_name;
    }
    void ChangeLastName(int year, const string &last_name)
    {
      if (year < birth_year)
        return;
      if (Year.count(year) == 0)
        Year[year].surname = "";
      Year[year].surname = last_name;
    }
    string GetFullName(int year) const
    {
      if (year < birth_year)
        return "No person";
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
    string GetFullNameWithHistory(int year) const
    {
      if (year < birth_year)
        return "No person";
      for (const auto &i : Year)
      {
        if (year < i.first)
          return "Incognito";
        break;
      }
      string n;
      string s;
      vector<string> second_names;
      vector<string> first_names;
      for (const auto &i : Year)
      {
        if (i.first <= year && i.second.surname != "")
        {
          if (i.second.surname != s && s != "")
            second_names.push_back(s);
          s = i.second.surname;
        }
        if (i.first <= year && i.second.name != "")
        {
          if (i.second.name != n && n != "")
            first_names.push_back(n);
          n = i.second.name;
        }
      }
      string secnames_string = "";
      string first_names_string = "";
      if (second_names.size() > 0)
      {
        secnames_string += " (" + second_names[second_names.size() - 1];
        if (second_names.size() > 1)
          for (int i = second_names.size() - 1; i > 0; --i)
          { secnames_string += ", " + second_names[i - 1]; }
        secnames_string += ")";
      }
      if (first_names.size() > 0)
      {
        first_names_string += " (" + first_names[first_names.size() - 1];
        if (first_names.size() > 1)
          for (int i = first_names.size() - 1; i > 0; --i)
          { first_names_string += ", " + first_names[i - 1]; }
        first_names_string += ")";
      }
      if (n == "")
        return s + secnames_string + " with unknown first name";
      else if (s == "")
        return n + first_names_string + " with unknown last name";
      else
        return n + first_names_string + " " + s + secnames_string;
    }
};

int main()
{
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
