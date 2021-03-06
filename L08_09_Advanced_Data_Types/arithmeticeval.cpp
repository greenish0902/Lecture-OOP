#include <iostream>

using namespace std;

int add(int x, int y) {
  return x + y;
}

int multiply(int x, int y) {
  return x * y;
}

int evaluate(int (*f)(int, int), int x, int y) {
  return f(x, y);
}

int main() {
  cout << add(2, 3) << '\n';
  cout << multiply(2, 3) << '\n';
  cout << evaluate(&add, 2, 3) << '\n';
  cout << evaluate(&multiply, 2, 3) << '\n';
}