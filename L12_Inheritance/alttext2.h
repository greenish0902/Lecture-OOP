#ifndef ALT_TEXT2_H_
#define ALT_TEXT2_H_
#include <string>

using namespace std;

enum class TextType { Plain, Fancy, Fixed, Bounded };

class AltText2 {
  TextType type;
  string text;
  string left_bracket;
  string right_bracket;
  string connector;
  size_t length_limit;
public:
  AltText2(TextType type);
  AltText2(TextType type, const string& t);
  AltText2(TextType type, const string& t, const string& left, const string& right, const string& conn);
  AltText2(TextType type, const string& t, size_t limit);
  string get() const;
  void append(const string& extra);
};

#endif