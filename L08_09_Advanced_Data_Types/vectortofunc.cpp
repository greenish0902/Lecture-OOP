#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v) {
  for (int elem : v) {
    cout << elem << " ";
  }
  cout << '\n';
}

int sum(vector<int> v) {
  int result = 0;
  for (int elem : v) {
    result += elem;
  }
  return result;
}

int main() {
  vector<int> list{ 2, 4, 6, 8 };
  print(list);
  cout << sum(list) << '\n';
  int n = list.size();
  for (int i = 0; i < n; i++) {
    list[i] = 0;
  }
  print(list);
  cout << sum(list) << '\n';
}