#include <iostream>
#include <string>

using namespace std;

class Account {
private:
  string id;
  string name;
  int balance;
  static bool print;
  static int balanceSum;
public:
  Account();
  ~Account();
  void setAccount(string, string, int);
};

Account::Account(): id(""), name(""), balance(0) {}
void Account::setAccount(string id, string name, int balance) {
  this->id = id;
  this->name = name;
  this->balance = balance;
  balanceSum += balance;
}
Account::~Account() {
  if (print) {
    cout << "회수된 금액 : " << balanceSum << endl;
    print = false;
  }
}
int Account::balanceSum = 0;
bool Account::print = true;

int main() {
  int total, i = 0, balance;
  string id, name;

  cout << "총 학생 수 입력: ";
  cin >> total;
  cout << endl;
  Account* acntArr = new Account[total];

  while (i < total) {
    cout << (i+1) << "번째 학생 계좌 입력 : " << endl;
    cout << "학번 : ";
    cin >> id;
    cout << "이름 : ";
    cin >> name;
    cout << "잔액 : ";
    cin >> balance;
    acntArr[i].setAccount(id, name, balance);
    cout << "============================" << endl;
    i++;
  }
  delete[] acntArr;
}