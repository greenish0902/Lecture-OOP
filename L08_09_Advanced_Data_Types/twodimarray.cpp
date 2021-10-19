#include <iostream>
#include <iomanip>

using namespace std;

const int ROWS = 3, COLUMNS = 5;

using Matrix = double[ROWS][COLUMNS];

void populate_matrix(Matrix m) {
  cout << "Enter the " << ROWS << " rows of the matrix.\n";
  for (int row = 0; row < ROWS; row++) {
    cout << "Row #" << row << " (enter " << COLUMNS << " values): ";
    for (int col = 0; col < COLUMNS; col++) {
      cin >> m[row][col];
    }
  }
}

void print_matrix(const Matrix m) {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLUMNS; col++) {
      cout << setw(5) << m[row][col];
    }
    cout << '\n';
  }
}

int main() {
  Matrix mat;
  populate_matrix(mat);
  print_matrix(mat);
}