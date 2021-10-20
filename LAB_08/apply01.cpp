#include <iostream>

using namespace std;

void square(int* num) {
  *num *= *num;
}

int main() {
  int input;
  cout << "input> ";
  cin >> input;
  square(&input);
  cout << "제곱값> " << input << endl;
}