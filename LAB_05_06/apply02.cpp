#include <iostream>

using namespace std;

int main() {
  int num, sum = 0;
  cout << "number : ";
  cin >> num;
  if (num >= 1) {
    for (int i = 1; i <= num; i++) {
      sum += i;
    }
    cout << "Sum of 1 to " << num << " = " << sum;
  } else
    cout << "wrong number" << endl;
}