#include <iostream>
#include <string>

using namespace std;

class CStudent {
private:
  int number;
  string name;
  string major;

public:
  CStudent(): number(2018000000), name("홍길동"), major("컴퓨터공학과") {}
  CStudent(int _number, string _name, string _major): number(_number), name(_name), major(_major) {}

  void setNumber(int _number) {
    number = _number;
  }
  void setName(string _name){
    name = _name;
    }
  void setMajor(string _major) {
    major = _major;
  }
  int getNumber() {
    return number;
  }
  string getName() {
    return name;
  }
  string getMajor() {
    return major;
  }
  void Display() {
    cout << "학번 : " << number << endl;
    cout << "이름 : " << name << endl;
    cout << "전공 : " << major << endl << endl;
  }
};

int main() {
	CStudent s[3]; // 3명의 학생정보를 저장할 class 배열
	int inputNumber; // 키보드로 학번을 입력 받을 변수
	string inputName, inputMajor; // 키보드로 이름, 전공을 입력 받을 변수
	int length = 0; // 현재 입력된 학생의 수
  bool duplicate = false;

	while (1) {
    cout << (length+1) << "번째 학생 입력" << endl;
    cout << "학번 : ";
    cin >> inputNumber;
    cout << "이름 : ";
    cin >> inputName;
    cout << "전공 : ";
    cin >> inputMajor;
    for (int i = 0; i < length; i++) {
      if (s[i].getNumber() == inputNumber) {
        cout << "✩✩✩ 중복된 학번이 존재합니다" << endl << endl;
        duplicate = true;
        continue;
      } else {
        duplicate = false;
      }
    }
    if (!duplicate) {
      s[length].setNumber(inputNumber);
      s[length].setName(inputName);
      s[length].setMajor(inputMajor);
      cout << "✩✩✩ 입력 완료" << endl << endl;
      length++;
    }
    if (length >= 3) {
      cout << "----모든 입력이 완료되었습니다----" << endl;
      for (int i = 0; i < length; i++) {
        cout << (i+1) << "학생정보" << endl;
        s[i].Display();
      }
      break;
    }
  }

	return 0;
}