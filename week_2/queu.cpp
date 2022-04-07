#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

int main()
{
  int Q;
  std::cin >> Q;
  vector<string> queu;

  for (int i = 0; i < Q; ++i)
  {
    string current;
    int code = 0;
    std::cin >> current;
    //std::cout << current << "!" << std::endl;
    if (current != "WORRY_COUNT")
    {std::cin >> code;}

    if (current == "QUIET" || current == "WORRY")
    {queu[code] = current; }

    else if (current == "COME" && code >= 0)
    {
      for (int j = 0; j < code; ++j)
      {queu.push_back("QUIET"); }
    }

    else if (current == "COME" && code < 0)
    {
      code = (-1) * code;
      for (int j = 0; j < code; ++j)
      {queu.pop_back(); }
    }

    else if (current == "WORRY_COUNT")
    {
      int counter_worry = 0;
      for (int j = 0; j < queu.size(); ++j)
      {
        if (queu[j] == "WORRY")
        {counter_worry += 1; }
      }
      std::cout << counter_worry << std::endl;
    }
  }
  return 0;
}