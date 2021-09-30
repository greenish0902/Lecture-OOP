#include <iostream>

using namespace std;

int main() {
  int loop = 5;
  while(loop) {
    int count = (6 - loop), num;
    cout << count << "번째 정수 : ";
    cin >> num;
    if (num % 2 == 0) {
      cout << num << "은(는) 짝수입니다." << endl;
    } else {
      cout << num << "은(는) 홀수입니다." << endl;
    }
    loop--;
  }
}