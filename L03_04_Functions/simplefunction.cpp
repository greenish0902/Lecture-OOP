#include <iostream>

void prompt() {
  std::cout << "Please enter an integer value: ";
}

int main() {
  int value1, value2, sum;
  std::cout << "This program adds together two integers.\n";
  prompt();
  std::cin >> value1;
  prompt();
  std::cin >> value2;
  sum = value1 + value2;
  std::cout << value1 << " + " << value2 << " = " << sum << '\n';
}