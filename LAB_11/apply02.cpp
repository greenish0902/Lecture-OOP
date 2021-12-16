#include <iostream>

using namespace std;

class Account {
private:
  string name, id;
  int balance;
public:
  Account(string, string, int);
  string getName() const;
  string getId() const;
  int getBalance() const;
  void setName(const string);
  void setId(const string);
  void setBalance(const int);
  Account operator+(const Account&);
  Account operator-(const Account&);
  Account& operator=(const Account&);
  friend ostream& operator<<(ostream& os, const Account& acnt);
};

Account::Account(string name, string id, int balance) {
  this->name = name;
  this->id = id;
  this->balance = balance;
}
string Account::getName() const { return name; }
string Account::getId() const { return id; }
int Account::getBalance() const { return balance;}
void Account::setName(const string name) { this->name = name; }
void Account::setId(const string id) { this->id = id; }
void Account::setBalance(const int balance) {this->balance = balance;}
Account Account::operator+(const Account& acnt) {
  Account result(this->name, this->id, this->getBalance() + acnt.getBalance());
  return result;
};
Account Account::operator-(const Account& acnt) {
  Account result(this->name, this->id, this->getBalance() - acnt.getBalance());
  return result;
};
Account& Account::operator=(const Account& acnt) {
  this->name = acnt.getName();
  this->id = acnt.getId();
  this->balance = acnt.getBalance();
  return *this;
};
ostream& operator<<(ostream& os, const Account& acnt) {
  return os << "학번: " << acnt.getId() << ", 이름: " << acnt.getName() << ", 잔액: " << acnt.getBalance() << endl;
}

int main() {
	Account acnt[3] = {
		Account("장윤호", "2014", 10000),
		Account("김유민", "2019", 0),
		Account("박진배", "2013", 5000),
	};

  bool find = false, condition;
  string id1, id2;
  Account *sender, *receiver;

  while(true) {
    find = false, condition = true;
    cout << "돈을 보낼 학생의 학번을 입력하세요: ";
    cin >> id1;
    if (id1 == "종료") {
      break;
    }
    for (Account& elem : acnt) {
      if (elem.getId() == id1) {
        sender = &elem;
        find = true;
        break;
        cout << elem.getId() << " exist\n";
      }
    }
    cout << "돈을 받을 학생의 학번을 입력하세요: ";
    cin >> id2;
    for (Account& elem : acnt) {
      if ((elem.getId() == id2) && find) {
        receiver = &elem;
        find = true;
        break;
      }
    }
    if (!find) {
      condition = false;
      cout << "보내는 학생 또는 받은 학생의 학번이 존재하지 않습니다. 다시 입력해주세요." << endl;
    }
    if ((sender->getBalance() == 0) && find) {
      condition = false;
      cout << "보내는 학생의 잔액이 부족합니다." << endl;
    }
    if ((id1 != id2) && condition) {
      *receiver = *receiver + *sender;
      *sender = *sender - *sender;
      cout << "보낸 학생의 잔액 => " << *sender;
      cout << "받은 학생의 잔액 => " << *receiver;
    }
  }
  cout << "종료합니다." << endl;
  for (Account elem : acnt) {
    cout << elem;
  }
}