#include <iostream>

using namespace std;

int main() {
  int power = 1;
  while (power <= 1000000000) {
    cout << power << '\n';
    power *= 10;
  }
}