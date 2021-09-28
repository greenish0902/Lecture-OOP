#include <iostream>

using namespace std;

int main() {
  int input, sum = 0;
  cout << "Enter numbers to sum, negative numbers ends list: ";
  while (true) {
    cin >> input;
    if (input < 0) {
      break;
      // continue;
    }
    sum += input;
  }
  cout << "Sum = " << sum << '\n';
}