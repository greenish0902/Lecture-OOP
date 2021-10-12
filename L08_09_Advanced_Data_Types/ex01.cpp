#include <iostream>

using namespace std;

int main() {
  int x = 4;
  int *p;

  cout << endl << "(1)[address of x: " << &x << "]" << "[value of x: " << x << "]";
  cout << endl << "(1)[pointed by p: " << p << "]" << "[value of pointed p: " << *p << "]";
  
  p = &x;

  cout << endl << "(1)[address of x: " << &x << "]" << "[value of x: " << x << "]";
  cout << endl << "(1)[pointed by p: " << p << "]" << "[value of pointed p: " << *p << "]";
  
  *p = 7;

  cout << endl << "(1)[address of x: " << &x << "]" << "[value of x: " << x << "]";
  cout << endl << "(1)[pointed by p: " << p << "]" << "[value of pointed p: " << *p << "]";

  return 0;
}