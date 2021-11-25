#include <string>
#include <vector>
#include <iostream>
#include "alttext2.h";

using namespace std;

int main() {
  vector<AltText2> texts { {TextType::Plain, "Wow"}, {TextType::Fancy, "Wee", "[", "]", "-"}, {TextType::Fixed}, {TextType::Bounded, "XYZ", 5}, {TextType::Fancy, "whoa", ":", ":", ":"} };
  
  for (auto t : texts) {
    cout << t.get() << endl;
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