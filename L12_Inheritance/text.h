#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include <string>

using namespace std;

class Text {
private:
  string text;
public:
  Text(const string& t);
  virtual string get() const;
  virtual void append(const string& extra);
};

#endif