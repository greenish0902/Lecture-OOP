#include <iostream>

int main() {
  int dividend, divisor;

  std::cout << "Please enter two integers to divide: ";
  std::cin >> dividend >> divisor;

  if (divisor != 0)
    std::cout << dividend << "/" << divisor << " = " << dividend/divisor << '\n';
  else
    std::cout << "Division by zero is not allowed\n";
}