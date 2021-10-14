#include <iostream>
#include <string>

using namespace std;

int main() {
  string data = "사랑,프로그래밍,의자,사랑의바보,영통역,천년의사랑,냉장고,객체지향"; 
  string keyword, word;
  int startIdx = 0, commaIdx, len;

  cout << "키워드 : ";
  cin >> keyword;
  cout << "검색결과 : ";

  while ((data.length() - startIdx) > 0 && (commaIdx != string::npos)) {
    commaIdx = data.substr(startIdx, (data.length() - startIdx)).find(",");
    word = data.substr(startIdx, commaIdx);
    if (word.find(keyword) != string::npos) {
      cout << word << " ";
    }
    startIdx += commaIdx + 1;
  }
  cout << endl;
}