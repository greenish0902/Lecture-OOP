#include <iostream>

using namespace std;

int main() {
  int in_value = -1;
  cout << "Please enter an integer in the range 0-10: ";

  while (in_value < 0 || in_value > 10) {
    cin >> in_value;
  }
  cout << "Legal value entered was " << in_value << '\n'; 
}