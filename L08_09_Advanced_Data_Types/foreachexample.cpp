#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<double> vec(10);

  cout << "Please enter 10 numbers: ";
  for (double& elem : vec) {
    cin >> elem;
  }
  for (double elem : vec) {
    cout << elem << '\n';
  }
}