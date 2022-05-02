#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;
using std::stringstream;
using std::runtime_error;
using std::getline;
using std::to_string;
using std::set;
using std::ostream;
using std::setw;
using std::setfill;
using std::out_of_range;

bool check_sep(stringstream &stream)
{
  if (stream.peek() != '-')
    return 0;
  stream.ignore(1);
  return 1;
}

class Date
{
  private:
    int year;
    int month;
    int day;

  public:
    Date(const string &new_date)
    {
      int new_year;
      int new_month;
      int new_day;
      stringstream stream(new_date);
      if (((stream >> new_year) && check_sep(stream) &&
           (stream >> new_month) && check_sep(stream) &&
           (stream >> new_day) && stream.eof()) == 0)
        throw runtime_error("Wrong date format: " + new_date);
      else if (new_month < 1 || new_month > 12)
        throw runtime_error("Month value is invalid: " + to_string(new_month));
      else if (new_day < 1 || new_day > 31)
        throw runtime_error("Day value is invalid: " + to_string(new_day));
      else
      {
        year  = new_year;
        month = new_month;
        day   = new_day;
      }
    }

    int get_year() const
    { return year; }
    int get_month() const
    { return month; }
    int get_day() const
    { return day; }
};

bool operator<(const Date &lhs, const Date &rhs)
{
  if (lhs.get_year() < rhs.get_year())
    return 1;
  if (lhs.get_year() == rhs.get_year())
  {
    if (lhs.get_month() < rhs.get_month())
      return 1;
    if (lhs.get_month() == rhs.get_month())
      if (lhs.get_day() < rhs.get_day())
        return 1;
  }
  return 0;
}

ostream &operator<<(ostream &stream, const Date &date)
{
  stream << setw(4) << setfill('0') << date.get_year() << "-" << setw(2)
         << date.get_month() << "-" << setw(2) << date.get_day();
  return stream;
}

class Database
{
  private:
    map<Date, set<string>> database;

  public:
    void AddEvent(const Date &date, const string &event)
    { database[date].insert(event); }

    bool DeleteEvent(const Date &date, const string &event)
    {
      int counter = 0;
      if (database.count(date) > 0 && database[date].count(event) > 0)
      {
        database[date].erase(event);
        return 1;
      }
      return 0;
    }

    int DeleteDate(const Date &date)
    {
      int N = 0;
      if (database.count(date) > 0)
      {
        N = database[date].size();
        database[date].clear();
      }
      return N;
    }

    void Find(const Date &date) const
    {
      try
      {
        for (auto &item : database.at(date))
          cout << item << endl;
      }
      catch (out_of_range &ex) {}
    }

    void Print() const
    {
      for (const auto &item : database)
        for (const auto &itemset : item.second)
          cout << item.first << " " << itemset << endl;
    }
};

void run(const string &command, Database &db)
{
  stringstream stream(command);
  string cmd;
  stream >> cmd;

  if (cmd == "Add")
  {
    string date, event;
    stream >> date;
    stream >> event;
    db.AddEvent(Date(date), event);

  }
  else if (cmd == "Del")
  {
    string date, event;
    stream >> date;
    if (stream >> event)
    {
      if (db.DeleteEvent(Date(date), event))
        cout << "Deleted successfully" << endl;
      else
        cout << "Event not found" << endl;
    }
    else
    {
      int N = db.DeleteDate(Date(date));
      cout << "Deleted " << N << " events" << endl;
    }

  }
  else if (cmd == "Find")
  {
    string date;
    stream >> date;
    db.Find(Date(date));
  }
  else if (cmd == "Print")
    db.Print();
  else
    throw runtime_error("Unknown command: " + cmd);
}

int main()
{
  Database db;
  string command;

  while (getline(cin, command))
  {
    try
    {
      if (command != "")
        run(command, db);
    }
    catch (runtime_error &ex)
    {
      cout << ex.what() << endl;
      return 1;
    }
  }
  return 0;
}
