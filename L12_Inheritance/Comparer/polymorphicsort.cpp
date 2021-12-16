#include <iostream>
#include <vector>
#include "comparer.h"

using namespace std;

void selection_sort(vector<int>& a, Comparer& compare) {
  int n = a.size();
  for (int i = 0; i < n - 1; i++) {
    int small = i;
    for (int j = i + 1; j < n; j++) {
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
  cout << "{";
  if (n > 0) {
    cout << a[0];
    for (int i = 1; i < n; i++) {
      cout << ", " << a[i];
    }
  }
  cout << "}";
}

bool less_than(int a, int b) {
  return a < b;
}

bool greater_than(int a, int b) {
  return a > b;
}

int main() {
  vector<int> original {23, -3, 4, 215, 0, -3, 2, 23, 100, 88, -10};
  
  vector<int> working = original;
  cout << "Before:  ";
  print(working);
  cout << endl;

  Comparer lt(less_than), gt(greater_than);
  selection_sort(working, lt);
  cout << "Asending:  ";
  print(working);
  cout << " (" << lt.comparisons() << "  comparisons, " << lt.swaps() << " swaps)" << endl;
  cout << "------------------------------" << endl;

  working = original;
  cout << "Before:  ";
  print(working);
  cout << endl;

  selection_sort(working, gt);
  cout << "Descending:  ";
  print(working);
  cout << " (" << gt.comparisons() << "  comparisons, " << gt.swaps() << " swaps)" << endl;
  cout << "------------------------------" << endl; 
  
  cout << "Before:  ";
  print(working);
  cout << endl;

  gt.reset();
  selection_sort(working, gt);
  cout << "Descending:  ";
  print(working);
  cout << " (" << gt.comparisons() << "  comparisons, " << gt.swaps() << " swaps)" << endl;
}