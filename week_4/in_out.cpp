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
  ifstream input(path_in);

  const string path_out = "output.txt";
  ofstream output(path_out);

  string line;
  while (getline(input, line))
  { output << line << endl; }
  return 0;
}