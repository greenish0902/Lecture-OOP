#include <iostream>

using namespace std;

int main() {
  int in_value;
  cout << "Please enter an integer in the range 0-10: ";

  do
  {
    cin >> in_value;
  } while (in_value < 0 || in_value > 10);
  cout << "Legal value entered was " << in_value << '\n';
}