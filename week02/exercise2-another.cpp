#include <iostream>

int another(int i) {
	int sum = 0;
	for (int j = 0; j <= i; j+=2)
	{
		sum += j;
	}
	return sum;
}

int main()
{
  int x = 0;
  std::cin >> x;
  std::cout << another(x);
}