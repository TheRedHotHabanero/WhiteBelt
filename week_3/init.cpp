#include <iostream>

struct Incognizable
{
	int a = 0;
	int d = 0;
};

int main()
{
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}