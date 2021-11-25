#include <iostream>
#include <fstream>

using namespace std;

void print(ostream& os, int n) {
  os.width(10);
  os.fill('*');
  os << n << endl;
}

int main() {
  print(cout, 35);
  
  ofstream fout("temp.data");
  if (fout.good()) {
    print(fout, 36);
  }
}