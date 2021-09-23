#include <iostream>

using namespace std;

int square(int x);

int main() {
  int x;
  x = 5;
  cout << square(x) << endl;
}

int square(int x) {
  return x * x;
}