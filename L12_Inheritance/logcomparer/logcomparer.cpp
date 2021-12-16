#include "logcomparer.h"
#include <cstdlib>
#include <iostream>

bool LogComparer::compare_impl(int m, int n) {
  fout << "Comparing " << m << " to " << n << endl;
  return Comparer::compare_impl(m, n);
}
void LogComparer::swap_impl(int& m, int& n) {
  fout << "Swapping " << m << " and " << n << endl;
  int temp = m;
  m = n;
  n = temp;
}
LogComparer::LogComparer(bool (*f)(int, int), const string& filename): Comparer(f) {
  fout.open(filename);
  if (!fout.good()) {
    cout << "Could not open log file " << filename << " for writing" << endl;
    exit(1);
  }
}