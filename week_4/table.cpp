
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::setw;
using std::string;

int main()
{
  const string path = "input.txt";
  ifstream input(path);

  int n = 0;
  int m = 0;

  if (input)
  {
    input >> n;
    input >> m;

    int x = 0;
    for (int i = 0; i < n; i++)
    {
      for (int k = 0; k < m; k++)
      {
        input >> x;
        input.ignore(1);
        cout << setw(10) << x;
        if (k != m - 1)
          cout << " ";
        else if (i != n - 1)
          cout << endl;
      }
    }
  }
  else
    cout << "error" << endl;
  return 0;
}