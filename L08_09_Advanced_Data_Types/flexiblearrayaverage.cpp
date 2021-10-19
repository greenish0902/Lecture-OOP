#include <iostream>

using namespace std;

int main() {
  double sum = 0.0;
  double *numbers;
  int size;

  cout << "Please enter number of values to process: ";
  cin >> size;

  if (size > 0) {
    cout << "Please enter: " << size << " numbers: ";
    numbers = new double[size];
    for (int i = 0; i < size; i++) {
      cin >> numbers[i];
      sum += numbers[i];
    }
    cout << "The average of ";
    for (int i = 0; i < size - 1; i++) {
      cout << numbers[i] << ", ";
    }
    cout << numbers[size - 1] << " is " << (sum/size) << '\n';
    delete[] numbers;
  }
}