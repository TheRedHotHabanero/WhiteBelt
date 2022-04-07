#include <iostream>

int main()
{
  double N, A, B, X, Y;
  std::cin >> N >> A >> B >> X >> Y;
  double cost = N;
  if (N > B)
  {
    // скидка в Y процентов
    cost = N * (100 - Y) / 100;
  }
  else if (N > A)
  {
    // скидка в X процентов
    cost = N * (100 - X) / 100;
  }
  std::cout << cost;
  return 0;
}