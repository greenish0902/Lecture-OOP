#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream fin ("apply05_txt.txt");
  ofstream fout ("apply05_output.txt");
  string content, line;
  int maxLen, idx = 0;

  cout << "length = ";
  cin >> maxLen;

  if (fin.is_open()) {
    while (getline(fin, line)) {
      content += line + ' ';
    }
    fin.close();
  }
  for (int idx = 0; idx <= content.length(); idx += maxLen) {
    fout << content.substr(idx, maxLen) << endl;
  }
  fout.close();
}