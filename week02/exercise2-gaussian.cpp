#include <iostream>

int gaussian(int i) {
	int sum = 0;
	for (int j = 1; j <= i; j++)
	{
		sum += j;
	}
	return sum;
}

int main()
{
  int x = 0;
  std::cin >> x;
  std::cout << gaussian(x);
}