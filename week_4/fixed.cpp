
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::atof;
using std::setprecision;
using std::fixed;
using std::getline;

int main()
{
  const string path = "input.txt";
  ifstream input(path);
  string line;
  while (getline(input, line))
  {
    double line2 = atof(line.c_str());
    cout << fixed << setprecision(3);
    cout << line2 << "\n";
  }
  return 0;
}