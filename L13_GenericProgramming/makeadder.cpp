#include <iostream>
#include <functional>

using namespace std;

function<int(int)> make_adder() {
  int loc_val = 2;
  return [loc_val](int x){ return x + loc_val; };
}

int main() {
  auto f = make_adder();
  cout << f(10) << endl;
  cout << f(2) << endl;
}