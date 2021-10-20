#include <iostream>
#include <vector>

using namespace std;

void reverseVecElem(vector<int> *vec) {
  for (int i = 0; i < ((*vec).size() / 2); i++) {
    int temp;
    temp = (*vec)[i];
    (*vec)[i] = (*vec)[(*vec).size() - 1 - i];
    (*vec)[(*vec).size() - 1 - i] = temp;
  }
}

int main() {
  vector<int> v(10);
  for (int i = 1; i <= 10; i++) {
    v[i-1] = i;
  }
  cout << "기본 Vector 값:" << endl;
  for (int elem : v) {
    cout << " " << elem;
  }
  cout << endl;
  reverseVecElem(&v);
  cout << "함수 실행 후 Vector 값:" << endl;
  for (int elem : v) {
    cout << " " << elem;
  }
  cout << endl;
}