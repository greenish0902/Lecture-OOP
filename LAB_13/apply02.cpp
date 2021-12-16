#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
  vector <int> vector1;
  vector <int> vector2;

  for (int i = 0; i < 10; i++) {
    int elem1 = rand() % 11;
    vector1.push_back(elem1);
  }
  for (int i = 0; i < 10; i++) {
    int elem2 = rand() % 21;
    vector2.push_back(elem2);
  }

  cout << "<vector 1>" << endl;
  int maxVal1 = 0, minVal1 = 100;
  for (auto iter = begin(vector1); iter < end(vector1); iter++) {
    cout << *iter << " ";
    if (*iter > maxVal1) {
      maxVal1 = *iter;
    }
    if (*iter < minVal1) {
      minVal1 = *iter;
    }
  }
  cout << endl;

  cout << "<vector 2>" << endl;
  int maxVal2 = 0, minVal2 = 100;
  for (auto iter = begin(vector2); iter < end(vector2); iter++) {
    cout << *iter << " ";
    if (*iter > maxVal2) {
      maxVal2 = *iter;
    }
    if (*iter < minVal2) {
      minVal2 = *iter;
    }
  }
  cout << endl << endl;

  cout << "최댓값 = " << (maxVal1 * maxVal2) << endl;
  cout << "최솟값 = " << (minVal1 * minVal2) << endl;
}