#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int size, row = 1;
  cout << "Please enter the table size: ";
  cin >> size;
  while (row <= size) {
    int column = 1;
    while (column <= size) {
      int product = row * column;
      cout << setw(4) << product;
      column++;
    }
    cout << '\n';
    row++;
  }
}