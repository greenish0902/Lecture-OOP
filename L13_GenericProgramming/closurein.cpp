#include <iostream>
#include <functional>

using namespace std;

int evaluate2(function<int(int, int)> f, int x, int y) {
  return f(x, y);
}

int main() {
  int a;
  cout << "Enter an integer: ";
  cin >> a;
  cout << evaluate2([a](int x, int y) {
    if (x == a) {
      x = 0;
    } else {
      y++;
    }
    return x + y;
  }, 2, 3) << endl;
}