#include <iostream>
#include <string>

using std::string;
using std::runtime_error;
using std::cin;
using std::endl;
using std::cout;

void EnsureEqual(const string& left, const string& right)
{
  if (left != right)
    throw runtime_error(left + " != " + right);
}

int main()
{
  try
  {
    EnsureEqual("C++ White", "C++ White");
    EnsureEqual("C++ White", "C++ Yellow");
  }
  catch (runtime_error& e)
  { cout << e.what() << endl; }
  return 0;
}