#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

int main() {
  int power = 1;
  cout.imbue(locale(""));
  while (power <= 1000000000) {
    cout << setw(13) << power << '\n';
    power *= 10;
  }
}