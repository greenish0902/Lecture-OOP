#include <string>
#include <iostream>

using namespace std;

class Text {
private:
  string text;
public:
  Text(const string& t): text(t) {}
  virtual string get() const {
    return text;
  }
  virtual void append(const string& extra) {
    text += extra;
  }
};

class FancyText: public Text {
private:
  string left_bracket;
  string right_bracket;
  string connector;
public:
  FancyText(const string& t, const string& left, const string& right, const string& conn): Text(t), left_bracket(left), right_bracket(right), connector(conn) {}
string get() const override {
  return left_bracket + Text::get() + right_bracket;
}

void append(const string& extra) override {
  Text::append(connector + extra);
}
};

class FixedText: public Text {
public:
  FixedText(): Text("FIXED") {}
  void append(const string&) override {}
};

int main() {
  Text t1("plain");
  FancyText t2("fancy", "<<", ">>", "***");
  FixedText t3;
  
  cout << t1.get() << endl;
  cout << t2.get() << endl;
  cout << t3.get() << endl;
  cout << "-----------------------" << endl;

  t1.append("A");
  t2.append("A");
  t3.append("A");

  cout << t1.get() << endl;
  cout << t2.get() << endl;
  cout << t3.get() << endl;
  cout << "-----------------------" << endl;

  t1.append("B");
  t2.append("B");
  t3.append("B");

  cout << t1.get() << endl;
  cout << t2.get() << endl;
  cout << t3.get() << endl;
}