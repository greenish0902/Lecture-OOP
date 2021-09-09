#include <iostream>
using namespace std;

int main() {
  float farenheit;
  cout << "Please enter Farenheit value: ";
  cin >> farenheit;
  float celcius = 5.0f / 9.0f * (farenheit - 32);
  cout << "Celcius value is " << celcius;
}