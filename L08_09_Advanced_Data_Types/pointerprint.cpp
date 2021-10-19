#include <iostream>

using namespace std;

int main() {
  int a[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int *p = a;

  for (int i = 0; i < 10; i++) {
    cout << *p << ' ';
    p++;
  }
  cout << '\n';
}