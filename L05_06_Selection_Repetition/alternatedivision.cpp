#include <iostream>

int main() {
  int dividend, divisor, quotient;

  std::cout << "Please enter two integers to divide: ";
  std::cin >> dividend >> divisor;

  if (divisor != 0) {
    quotient = dividend / divisor;
    std::cout << dividend << " divided by " << divisor << " is " << quotient << '\n';
  }
}