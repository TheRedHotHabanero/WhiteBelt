#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Student
{
  string name;
  string surname;

  int day;
  int month;
  int year;
};

int main()
{
  int n;
  cin >> n;
  string name;
  string surname;

  int day;
  int month;
  int year;

  vector<Student> students;
  for (int i = 0; i < n; ++i)
  {
    cin >> name >> surname >> day >> month >> year;
    students.push_back(Student{name, surname, day, month, year});
  }

  int m;
  cin >> m;
  string request;
  int qual_stud;

  for (int i = 0; i < m; ++i)
  {
    cin >> request >> qual_stud;
    qual_stud = qual_stud - 1;

    if (request == "name" && qual_stud >= 0 && qual_stud < n)
      cout << students[qual_stud].name << " " << students[qual_stud].surname << endl;
    else if (request == "date" && qual_stud >= 0 && qual_stud < n)
      cout << students[qual_stud].day << "." << students[qual_stud].month << "." << students[qual_stud].year << endl;
    else
      cout << "bad request" << endl;
  }

  return 0;
}