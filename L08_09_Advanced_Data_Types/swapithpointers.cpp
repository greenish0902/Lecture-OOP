#include <iostream>

using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int var1 = 5, var2 = 19;
  cout << "var1 = " << var1 << ", var2 = " << var2 << '\n';
  swap(&var1, &var2);
  cout << "var1 = " << var1 << ", var2 = " << var2 << '\n';
}