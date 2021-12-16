#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

template <typename T>
class Comparer {
private:
  int compare_count;
  int swap_count;
  bool (*comp)(const T&, const T&);
protected:
  virtual bool compare_impl(const T& m, const T& n);
  virtual void swap_impl(T& m, T& n);
public:
  Comparer(bool (*f)(const T&, const T&));
  void reset();
  bool compare(const T& m, const T& n);
  void swap(T& m, T& n);
  int comparisons() const;
  int swaps() const;
};

template <typename T>
bool Comparer<T>::compare_impl(const T& m, const T& n) {
  return comp(m, n);
}

template <typename T>
void Comparer<T>::swap_impl(T& m, T& n) {
  T temp = m;
  m = n;
  n = temp;
}

template <typename T>
Comparer<T>::Comparer(bool (*f)(const T&, const T&)): compare_count(0), swap_count(0), comp(f) {}

template <typename T>
void Comparer<T>::reset() {
  compare_count = swap_count = 0;
}

template <typename T>
bool Comparer<T>::compare(const T& m, const T& n) {
  compare_count++;
  return compare_impl(m, n);
}

template <typename T>
void Comparer<T>::swap(T& m, T& n) {
  swap_count++;
  swap_impl(m, n);
}

template <typename T>
int Comparer<T>::comparisons() const {
  return compare_count;
}

template <typename T>
int Comparer<T>::swaps() const {
  return swap_count;
}

template <typename T, typename V>
void selection_sort(const T begin, const T end, Comparer<V>& compare) {
  for (auto i = begin; i != end - 1; i++) {
    auto small = i;
    for (auto j = i + 1; j != end; j++) {
      if (compare.compare(*j, *small)) {
        small = j;
      }
    }
    if (i != small) {
      compare.swap(*i, *small);
    }
  }
}

template <typename T>
void print(const T begin, const T end) {
  cout << "{";
  if (begin != end) {
    T iter = begin;
    cout << *iter;
    iter++;
    while (iter != end) {
      cout << ", " << *iter;
      iter++;
    }
  }
  cout << "}";
}

template <typename T>
bool less_than(const T& a, const T& b) {
  return a < b;
}

template <typename T>
bool greater_than(const T& a, const T& b) {
  return a > b;
}

template <typename T>
class LogComparer: public Comparer<T> {
private:
  ofstream fout;

protected:
  bool compare_impl(const T& m, const T& n) override;
  void swap_impl(T& m, T& n) override;

public:
  LogComparer(bool (*f)(const T&, const T&), const string& filename);
  ~LogComparer() {}
};

template <typename T>
bool LogComparer<T>::compare_impl(const T& m, const T& n) {
  fout << "Comparing " << m << " to " << n << endl;
  return Comparer<T>::compare_impl(m, n);
}

template <typename T>
void LogComparer<T>::swap_impl(T& m, T& n) {
  fout << "Swapping " << m << " and " << n << endl;
  Comparer<T>::swap_impl(m, n);
}

template <typename T>
LogComparer<T>::LogComparer(bool (*f)(const T&, const T&), const string& filename): Comparer<T>(f) {
  fout.open(filename);
  if (!fout.good()) {
    cout << "Could not open log file " << filename << " for writing" << endl;
    exit(1);
  }
}

int main() {
  vector<int> vec = {23, -3, 10, 4, 215, 0, -3, 2};
  cout << "Before:    ";
  print(begin(vec), end(vec));
  cout << endl;
  
  LogComparer<int> lt(less_than<int>, "upsort.log");
  selection_sort(begin(vec), end(vec), lt);
  cout << "Ascending:   ";
  print(begin(vec), end(vec));
  cout << "   (" << lt.comparisons() << " comparisons, " << lt.swaps() << " swaps)" << endl;
  
  LogComparer<int> gt(greater_than<int>, "downsort.log");
  selection_sort(begin(vec), end(vec), gt);
  cout << "Descending:    ";
  print(begin(vec), end(vec));
  cout << "   (" << gt.comparisons() << " comparisons, " << gt.swaps() << " swaps)" << endl;
  cout << "--------------------------------------" << endl;

  vector<string> words = {"tree", "girl", "boy", "dog", "cat", "girl", "bird"};
  cout << "Before:    ";
  print(begin(words), end(words));
  cout << endl;

  LogComparer<string> wlt(less_than<string>, "upwords.log");
  selection_sort(begin(words), end(words), wlt);
  cout << "Ascending:   ";
  print(begin(words), end(words));
  cout << "   (" << wlt.comparisons() << " comparisons, " << wlt.swaps() << " swaps)" << endl;

  LogComparer<string> wgt(greater_than<string>, "downwords.log");
  selection_sort(begin(words), end(words), wgt);
  cout << "Descending:    ";
  print(begin(words), end(words));
  cout << "   (" << wgt.comparisons() << " comparisons, " << wgt.swaps() << " swaps)" << endl;
  cout << "--------------------------------------" << endl;

  int arr[] = {23, -3, 10, 4, 215, 0, -3, 2};
  cout << "Before:    ";
  print(arr, arr + 8);
  cout << endl;

  LogComparer<int> lt2(less_than<int>, "upsort2.log");
  selection_sort(arr, arr + 8, lt2);
  cout << "Ascending:   ";
  print(arr, arr + 8);
  cout << "   (" << lt2.comparisons() << " comparisons, " << lt.swaps() << " swaps)" << endl;
  
  LogComparer<int> gt2(greater_than<int>, "downsort2.log");
  selection_sort(arr, arr + 8, gt2);
  cout << "Descending:    ";
  print(arr, arr + 8);
  cout << "   (" << gt2.comparisons() << " comparisons, " << gt.swaps() << " swaps)" << endl;
}