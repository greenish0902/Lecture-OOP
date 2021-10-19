#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

using Matrix = vector<vector<double>>;

void print(const Matrix& m) {
  for (const vector<double>& row : m) {
    for (int elem : row) {
      cout << setw(5) << elem;
    }
    cout << '\n';
  }
}

void print(const Matrix& m) {
  for (auto row : m) {
    for (int elem : row) {
      cout << setw(5) << elem;
    }
    cout << '\n';
  }
}

int main() {
}