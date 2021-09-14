#include <iostream>

using namespace std;

int makeDouble(int param) {
  int x;
  cout << "03: " << x << '\n';
  x = param;
  cout << "04: " << x << '\n';
  return param * 2;
}


int main() {
  int x = 10;
  cout << "01: " << x << '\n';
  x = makeDouble(x);
  cout << "02: " << x << '\n';
  return 0;
}