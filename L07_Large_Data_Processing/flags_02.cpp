#include <iostream>

using namespace std;

int main() {
  cout << "Default justification:  |";
  cout.width(10);
  cout << 12345 << "|\n";
  cout.setf(ios::left, ios::adjustfield);
  
}