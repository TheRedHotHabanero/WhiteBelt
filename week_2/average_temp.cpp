#include <iostream>
#include <vector>

int main()
{
  int N;
  std::cin >> N;
  std::vector<int> days;
  int sum = 0;
  for (int i = 0; i < N; ++i)
  {
    int current;
    std::cin >> current;
    days.push_back(current);
    sum += current;
  }
  double average = sum / days.size();
  int counter = 0;
  for (int i = 0; i < N; ++i)
  {
    if (days[i] > average)
    {counter += 1; }
  }
  std::cout << counter << std::endl;
  for (int i = 0; i < N; ++i)
  {
    if (days[i] > average)
    {std::cout << i << " "; }
  }
  return 0;
}