#include <iostream>

using namespace std;

int main() {
  int num;

  while(true) {
    cout << "Enter the number (0, 10]: ";
    cin >> num;
    if (num < 10 && num > 0)
      break;
    // if (num > 10 || num <= 0 || int(num) != num) {
    //   continue;
    // }
    // break;
  }
  cout << "Success!" << endl;
  return 0;
}