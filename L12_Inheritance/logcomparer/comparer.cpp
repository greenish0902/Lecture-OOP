#include "comparer.h"

Comparer::Comparer(bool (*f)(int, int)) : compare_count(0), swap_count(0), comp(f) {}

bool Comparer::compare_impl(int m, int n) {
  return comp(m, n);
}
void Comparer::swap_impl(int& m, int& n) {
  int temp = m;
  m = n;
  n = temp;
}
void Comparer::reset() {
  compare_count = swap_count = 0;
}
bool Comparer::compare(int m, int n) {
  compare_count++;
  return compare_impl(m, n);
}
void Comparer::swap(int& m, int& n) {
  swap_count++;
  swap_impl(m, n);
}
int Comparer::comparisons() const {
  return compare_count;
}
int Comparer::swaps() const {
  return swap_count;
}