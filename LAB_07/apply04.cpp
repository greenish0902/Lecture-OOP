#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
  string line;
  ifstream fin;
  ofstream fout ("apply04_output.txt");

  fin.open("apply04_txt01.txt");
  if (fin.is_open()) {
    while(getline(fin, line)) {
      fout << line << endl;
    }
    fin.close();
    fout << endl;
  }
  fin.open("apply04_txt02.txt");
  if (fin.is_open()) {
    while(getline(fin, line)) {
      fout << line << endl;
    }
    fin.close();
  }
  fout.close();
}