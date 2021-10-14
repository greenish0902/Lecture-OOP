#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
  ofstream fin;
  fin.open("apply03_matrix.txt");

  for (int row = 1; row <= 10; row++) {
    for (int col = 1; col <= 10; col++) {
      fin << rand() % 101 << "  ";
    }
    fin << endl;
  }
  
  fin.close();
}