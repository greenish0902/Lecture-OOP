#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double input;
  cout << "Enter number: ";
  cin >> input;
  double root = sqrt(input);
  cout << "Square root of " << input << " = " << root << '\n';
}