#include <iostream>
#include <string>
#include <map>

using std::map;
using std::string;
using std::cin;
using std::cout;

void CHANGE_CAPITAL (string country, string new_capital, map<string, string>& country_to_capital)
{
  if (country_to_capital.count(country) == 0)
  {
    cout << "Introduce new country " << country << " with capital " << new_capital << "\n";
  }
  else
  {
    const string& old_capital = country_to_capital [country];
    if (old_capital == new_capital)
		{
    	cout << "Country " << country << " hasn't changed its capital" << "\n";
    }
		else
		{
      cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << "\n";
    }
  }

	country_to_capital[country] = new_capital;
}

void RENAME (string old_country_name, string new_country_name, map<string, string>& country_to_capital)
{
  if (old_country_name == new_country_name || country_to_capital.count(old_country_name) == 0 || country_to_capital.count(new_country_name) == 1)
	{
    cout << "Incorrect rename, skip" << "\n";
  }
  else
	{
    cout << "Country " << old_country_name << " with capital " << country_to_capital [old_country_name] << " has been renamed to " << new_country_name << "\n";
    country_to_capital[new_country_name] = country_to_capital[old_country_name];
    country_to_capital.erase(old_country_name);
  }
}

void ABOUT (string country, map<string, string>& country_to_capital)
{
  if (country_to_capital.count(country) == 0)
	{
    cout << "Country " << country << " doesn't exist" << "\n";
  }
	else
	{
  	cout << "Country " << country << " has capital " << country_to_capital[country] << "\n";
  }
}

void DUMP (map<string, string>& country_to_capital)
{
  if (country_to_capital.empty())
	{
    cout << "There are no countries in the world" << "\n";
  }
	else
	{
    for (const auto& country_item : country_to_capital)
		{
      cout << country_item.first << "/" << country_item.second << " ";
    }
    cout << "\n";
  }
}

int main()
{
  int Q;
  cin >> Q;
  map<string, string> country_to_capital;

  for (int i = 0; i < Q; ++ i)
	{
  	string COM;
    cin >> COM;

    if (COM == "CHANGE_CAPITAL")
		{
      string country, new_capital;
      cin >> country >> new_capital;
      CHANGE_CAPITAL (country, new_capital, country_to_capital);
    }
    else if (COM == "RENAME")
		{
      string old_country_name, new_country_name;
      cin >> old_country_name >> new_country_name;
      RENAME (old_country_name, new_country_name, country_to_capital);
    }
    else if (COM == "ABOUT")
		{
      string country;
      cin >> country;
      ABOUT (country, country_to_capital);
    }
    else if (COM == "DUMP")
		{
      DUMP (country_to_capital);
    }
  }

  return 0;
}