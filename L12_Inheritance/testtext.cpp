#include <iostream>
#include "text.h"
#include "fancytext.h"
#include "fixedtext.h"

int main() {
  Text t1("plain");
  FancyText t2("fancy", "<<", ">>", "***");
  FixedText t3;

  cout << t1.get() << endl;
  cout << t2.get() << endl;
  cout << t3.get() << endl;
  cout << "--------------------------" << endl;

  t1.append("A");
  t2.append("A");
  t3.append("A");

  cout << t1.get() << endl;
  cout << t2.get() << endl;
  cout << t3.get() << endl;
  cout << "--------------------------" << endl;

  t1.append("B");
  t2.append("B");
  t3.append("B");

  cout << t1.get() << endl;
  cout << t2.get() << endl;
  cout << t3.get() << endl;
}