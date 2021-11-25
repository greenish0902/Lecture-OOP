#include <string>
#include <vector>
#include <iostream>
#include "alttext.h"

using namespace std;

int main() {
  vector<AltText> texts { {TextType::Plain, "Wow"}, {TextType::Fancy, "Wee", "[", "]", "-"}, {TextType::Fixed}, {TextType::Fancy, "whoa", ":", ":", ":"} };
  for (auto t : texts) {
    cout << t.get() << '\n';
  }
  for (auto& t : texts) {
    t.append("A");
    t.append("B");
    t.append("C");
  }
  for (auto t : texts) {
    cout << t.get() << endl;
  }
}