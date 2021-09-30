#include <iostream>

using namespace std;

int main() {
  int num;
  while (true) {
    cout << "단 수를 입력하세요: ";
    cin >> num;
    if (num >= 1 && num <= 9 && (num == int(num))) {    
      for (int i = 1; i < 10; i ++) {
        cout << num << " * " << i << " = " << (num*i) << endl;
      }
    } else if (num == -1) {
      cout << "종료합니다." << endl;
      break;
    } else {
      cout << "1부터 9까지의 정수를 입력해주세요." << endl;
    }
    cout << endl;
  }
}