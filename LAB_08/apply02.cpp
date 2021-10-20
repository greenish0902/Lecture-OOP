#include <iostream>
#include <string>

using namespace std;

void changeVal(string* str) {
  string newStr;
  cout << "input> ";
  cin >> newStr;
  *str = newStr;
}

int main() {
  string str = "This is default value";
  cout << "기본값 출력> " << str << endl;
  changeVal(&str);
  cout << "변환된 값 출력> " << str << endl;
  return 0;
}