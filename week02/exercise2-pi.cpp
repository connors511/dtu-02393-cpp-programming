#include <iostream>

double pi(int n) {
  double sum = 0.0;
  int sign = 1;
  double tmp;

  for (int i = 0; i < n; i++)
  {
    sign = (i % 2 == 0) ? 1 : -1;
    sum += (double) sign / (2*i + 1);
  }
  return sum * 4;
}

int main()
{
  int x = 0;
  std::cin >> x;
  std::cout << pi(x);
}