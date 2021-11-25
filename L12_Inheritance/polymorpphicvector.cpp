#include <iostream>
#include <string>
#include <vector>
#include "fancytext.h"
#include "fixedtext.h"

using namespace std;

int main() {
  vector<Text *> texts { new Text("Wow"), new FancyText("Wee", "[", "]", "-"), new FixedText, new FancyText("whoa", ":", ":", ":")};
  for (auto t : texts) {
    cout << t->get() << endl;
  }
  for (auto t : texts) {
    t->append("A");
    t->append("B");
    t->append("C");
  }
  for (auto t : texts) {
    cout << t->get() << endl;
  }
  for (auto t : texts) {
    delete t;
  }
}