#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
using Matrix = vector<vector<int>>;

void rowChecker(int& row, int size);
void colChecker(int& col, int size);
void matPrint(const Matrix mat);

int main() {
  int size = 0;
  cout << "홀수 숫자를 하나 입력해 주세요 : ";
  cin >> size;

  int value = 1, row = 0, col = (size / 2);
  Matrix mat(size, vector<int>(size));

  while (value <= size * size) {
    if (mat[row][col] != 0) {
      row += 2; col--;
      rowChecker(row, size); colChecker(col, size);
    }
    mat[row][col] = value;
    value++; row--; col++;
    rowChecker(row, size); colChecker(col, size);
  }
  matPrint(mat);
}

void rowChecker(int& row, int size) {
  if (row < 0) {
    row += size;
  } else if (row > size) {
    row -= size;
  }
}
void colChecker(int& col, int size) {
  if (col > size - 1) {
    col -= size;
  } else if (col < 0) {
    col += size;
  }
}
void matPrint(const Matrix mat) {
  for (auto row : mat) {
    for (int elem : row) {
      cout << setw(5) << elem;
    }
    cout << endl;
  }
}