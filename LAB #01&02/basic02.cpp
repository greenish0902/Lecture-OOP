#include <iostream>
using namespace std;

// sizeof(type) or sizeof(변수명): 타입 또는 변수명의 타입의 사이즈 
int main() {
  unsigned short siX;
  unsigned iX;
  long liX;
  long long lliX;
  cout << "sieof(siX): " << sizeof(siX) << endl;
  cout << "sieof(unsigned short): " << sizeof(unsigned short) << endl;
  cout << "sieof(iX): " << sizeof(iX) << endl;
  cout << "sieof(unsigned): " << sizeof(unsigned) << endl;
  cout << "sieof(liX): " << sizeof(liX) << endl;
  cout << "sieof(long): " << sizeof(long) << endl;
  cout << "sieof(lliX): " << sizeof(lliX) << endl;
  cout << "sieof(long long): " << sizeof(long long) << endl;
}