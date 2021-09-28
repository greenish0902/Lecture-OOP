#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int power = 1;
  while (power <= 1000000000) {
    cout << setw(10) << power << '\n';
    power *= 10;
  }
}