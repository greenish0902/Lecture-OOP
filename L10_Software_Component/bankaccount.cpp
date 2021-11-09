#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
public:
  string name;
  int id;
  double balance;
};

void add_account(vector<Account>& accts) {
  string name;
  int number;
  double amount;

  cout << "Enter name, account number, and account balance: ";
  cin >> name >> number >> amount;

  Account acct;
  acct.name = name;
  acct.id = number;
  acct.balance = amount;
  accts.push_back(acct);
}

void print_accounts(const vector<Account>& accts) {
  int n = accts.size();
  for (int i = 0; i < n; i++) {
    cout << accts[i].name << ", " << accts[i].id << ", " << accts[i].balance << '\n';
  }
}

void swap(Account& er1, Account& er2) {
  Account temp = er1;
  er1 = er2;
  er2 = temp;
}

bool less_than_by_name(const Account& e1, const Account& e2) {
  return e1.name < e2.name;
}

bool less_than_by_id(const Account& e1, const Account& e2) {
  return e1.id < e2.id;
}

bool less_than_by_balance(const Account& e1, const Account& e2) {
  return e1.balance < e2.balance;
}

void sort(vector<Account>& db, bool (*comp)(const Account&, const Account&)) {
  int size = db.size();
  for (int i = 0; i < size - 1; i++) {
    int smallest = i;
    for (int j = i + 1; j < size; j++) {
      if (comp(db[j], db[smallest])) {
        smallest = j;
      }
    }
    if (smallest != i) {
      swap(db[i], db[smallest]);
    }
  }
}

int main() {
  vector<Account> customers;

  char cmd;
  bool done = false;

  do {
    cout << "[A]dd [N]ame [I]D [B]alance [Q]uit==> ";
    cin >> cmd;
    switch (cmd) {
      case 'A':
      case 'a':
        add_account(customers);
        break;
      case 'P':
      case 'p':
        print_accounts(customers);
      case 'N':
      case 'n':
        sort(customers, less_than_by_name);
        print_accounts(customers);
        break;
      case 'I':
      case 'i':
        sort(customers, less_than_by_id);
        print_accounts(customers);
        break;
      case 'B':
      case 'b':
        sort(customers, less_than_by_balance);
        print_accounts(customers);
        break;
      case 'Q':
      case 'q':
        done = true;
        break;
    }
  }
  while (!done);
}