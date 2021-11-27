#ifndef ALT_TEXT_H_
#define ALT_TEXT_H_

#include <string>

using namespace std;

enum class TextType {
  Plain, Fancy, Fixed 
};

class AltText {
private:
  TextType type;
  string text;
  string left_bracket;
  string right_bracket;
  string connector;
public:
  AltText(TextType type);
  AltText(TextType type, const string& t);
  AltText(TextType type, const string& t, const string& left, const string& right, const string& conn);
  string get() const;
  void append(const string& extra);
};

#endif