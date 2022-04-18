#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

struct Specialization
{
  string value;
  explicit Specialization(string new_val)
  { value = new_val; }
};

struct Course
{
  string value;
  explicit Course(string new_val)
  { value = new_val; }
};

struct Week
{
  string value;
  explicit Week(string new_val)
  { value = new_val; }
};

struct LectureTitle
{
  string specialization;
  string course;
  string week;

  LectureTitle(Specialization new_specialization, Course new_course, Week new_week)
  {
    specialization = new_specialization.value;
    course = new_course.value;
    week = new_week.value;
  }
};

int main()
{
  LectureTitle title( Specialization("C++"),
                      Course("White belt"),
                      Week("4th") );
}