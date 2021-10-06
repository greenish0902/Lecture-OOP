#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ofstream fsTemp;
  fsTemp.open("temp.txt");
  int a = 123;
  double b = 12.12345678;

  fsTemp.width(15);
  fsTemp << a << endl;
  fsTemp.width(15);
  fsTemp.precision(10);
  fsTemp << b << endl;

  fsTemp.close();
  return 0;
}