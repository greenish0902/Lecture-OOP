#include <iostream>

using namespace std;

int gcd(int&, int&);

int main() {
  int x, y;
  cout << "x = ";
  cin >> x;
  cout << "y = ";
  cin >> y;
  cout << "gcd(" << x << "," << y << ") = " << gcd(x, y);
}

int gcd(int& a, int& b) {
  int tmp;
  while (b != 0) {
    tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}