#include <iostream>
#include <string>

using namespace std;

int main() {
  string word = "fred";
  cout << word.length() << '\n';
  if (word.empty()) {
    cout << "empty\n";
  } else {
    cout << "not empty\n";
  }
  word.clear();
  if (word.empty()) {
    cout << "empty\n";
  } else {
    cout << "not empty\n";
  }
  word = "good";
  cout << word << '\n';
  word += "-bye";
  cout << word << '\n';
  cout << word[0] << '\n';
  cout << word[word.length()-1] << '\n';
  cout << word.substr(2, 5) << '\n';
  string first = "ABC", last = "XYZ";
  cout << first + last << '\n';
  cout << "Compare " << first << " and ABC: ";
  if (first == "ABC") {
    cout << "equal\n";
  } else {
    cout << "not equal\n";
  }
  cout << "Compare " << first << " and XYZ: ";
  if (first == "XYZ") {
    cout << "equal\n";
  } else {
    cout << "not equal\n";
  }
}