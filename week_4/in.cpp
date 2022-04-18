#include <fstream>
#include <iostream>
#include <string>

using std::ifstream;
using std::string;
using std::ofstream;
using std::cin;
using std::cout;
using std::ios;
using std::endl;

int main()
{
  const string path_in = "input.txt";
  const string path_out = "output.txt";
  ifstream input("input.txt");
  ofstream outout(path_out);

  string line;
  ofstream output("output.txt", ios::app);
  if (input)
  {
    while (getline(input, line))
    { cout << line << endl; }
  }
  else
    cout << "error" << endl;

  return 0;
}