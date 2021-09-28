#include <iostream>
#include <iomanip>

int main() {
  int size;
  std::cout << "Please enter the table size: ";
  std::cin >> size;

  std::cout << "      ";
  for (int column = 1; column <= size; column++)
    std::cout << std::setw(4) << column;
  std::cout << '\n';

  std::cout << "     +";
  for (int column = 1; column <= size; column++)
    std::cout << "----";
  std::cout << '\n';

  for (int row = 1; row <= size; row++) {
    std::cout << std::setw(4) << row << " |";
    for (int column = 1; column <= size; column++)
      std::cout << std::setw(4) << row*column;
    std::cout << '\n';
  }
}