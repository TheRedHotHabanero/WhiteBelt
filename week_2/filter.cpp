#include <iostream>
#include <vector>
using std::string;

bool IsPalindrom(string mazafaka)
{
  int length = mazafaka.size();
  bool isPal = true;
  for (int i = 0; i < (length / 2); ++i)
  {
    if (mazafaka[i] != mazafaka[length - i - 1])
    {
      isPal = false;
      return isPal;
    }
  }
  return isPal;
}

std::vector<string> PalindromFilter(std::vector<string> words, int minLength)
{
  std::vector<string> answer;
  for (int i = 0; i < words.size(); ++i)
  {
    if (IsPalindrom(words[i]) == true && words[i].size() >= minLength)
    {answer.push_back(words[i]);}
  }
  return answer;
}

int main()
{
  return 0;
}