#include <iostream>
#include <vector>
#include "logcomparer.h"

void selection_sort(vector<int>& a, Comparer& compare) {
  int n = a.size();
  for (int i = 0; i < n - 1; i++) {
    int small = i;
    for (int j = i; j < n; j++) {
      if (compare.compare(a[j], a[small])) {
        small = j;
      }
    }
    if (i != small) {
      compare.swap(a[i], a[small]);
    }
  }
}

void print(const vector<int>& a) {
  int n = a.size();
  cout << " {";
  if (n > 0) {
    cout << a[0];
    for (int i = 1; i < n; i++) {
      cout << ", " << a[i];
    }
    cout << "} ";
  }
}

bool less_than(int a, int b) {
  return a < b;
}

int main() {
  int a[] = {23, -3, 4, 215, 0, -3, 2};
  int len = (sizeof a) / (sizeof a[0]);
  vector<int> vec(a, a + len);

  cout << "Before:   ";
  print(vec);
  cout << endl;
  
  LogComparer lt(less_than, "sort.log");
  selection_sort(vec, lt);
  cout << "Ascending:   ";
  print(vec);

  cout << "   (" << lt.comparisons() << " comparisons, " << lt.swaps() << " swaps)" << endl;
}