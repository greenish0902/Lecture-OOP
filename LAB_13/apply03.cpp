#include <iostream>
#include <string>
#include <functional>

using namespace std;

function<bool(string)> compare(function<string(string)> f) {
  return [f](string inputStr) { return (f(inputStr) == inputStr) ? 1 : 0; };
}

string getReversed(string inputStr) {
  string outputStr;
  for (int i = inputStr.size(); i >= 0; i--) {
    outputStr += inputStr.substr(i, 1);
  }
  return outputStr;
}

int main() {
  auto comp = compare(getReversed);

  while (true) {
    string inputStr;
    cout << "문자열 하나를 입력해주세요 : ";
    cin >> inputStr;
    if ((inputStr == "Q") || (inputStr == "q")) {
      break;
    }

    string reverseStr = getReversed(inputStr);
    cout << "입력하신 문자열의 역순 : " << reverseStr << endl;

    cout << "이 문자는 ";
    if (comp(inputStr)) {
      cout << "회문입니다." << endl;
    } else {
      cout << "회문이 아닙니다." << endl;
    }
    cout << endl;
  }
}