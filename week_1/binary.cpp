#include <iostream>
#include <vector>
/*
int main()
{
  int N;
  std::cin >> N;
  int binary_num = 0;
  int count = 0;
  while (N > 0)
  {
    int num = N % 2;
    count += 1;
    N /= 2;
    binary_num = binary_num * 10 + num;
  }
  int count_bin = 0;
  for (int i = 0; i < count; ++i)
  {
    std::cout << binary_num % 10;
    binary_num /= 10;
    if (binary_num < 0)
    {std::cout << 0; }
  }
  return 0;
}
*/
int main()
{
  int N;
  std::cin >> N;
  std::vector<int> visa;
  while (N > 0)
  {
    visa.push_back(N % 2);
    N /= 2;
  }
  int length = visa.size();
  for (int i = 0; i < visa.size(); ++i)
  {
    std::cout << visa[length - i - 1];
  }
  return 0;
}