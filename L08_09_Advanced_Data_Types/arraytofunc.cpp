#include <iostream>

using namespace std;

void print(int a[], int n) {
  for (int i = 0 ; i < n ; i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
}

int sum(int a[], int n) {
  int result = 0;
  for (int i = 0; i < n; i++) {
    result += a[i];
  }
  return result;
}

int main() {
  int list[] = {2, 4, 6, 8};
  print(list, 4);
  cout << sum(list, 4) << '\n';
  for (int i = 0; i < 4; i++) {
    list[i] = 0;
  }
  print(list, 4);
  cout << sum(list, 4) << '\n';
}