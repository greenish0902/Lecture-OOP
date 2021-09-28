#include <iostream>

using namespace std;

int main() {
  int input = 0, sum = 0;

  cout << "Enter numbers to sum, negative number ends list: ";

  while (input >= 0) {
    cin >> input;
    if (input >= 0)
      sum += input;
  }
  cout << "Sum = " << sum << '\n';
}