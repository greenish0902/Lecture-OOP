#include "alttext.h"

AltText::AltText(TextType type): type(type), text("FIXED") {}
AltText::AltText(TextType type, const string& t): type(type), text(t) {}
AltText::AltText(TextType type, const string& t, const string& left, const string& right, const string& conn): type(type), text(t), left_bracket(left), right_bracket(right), connector(conn) {}

string AltText::get() const {
  switch (type) {
    case TextType::Plain:
    case TextType::Fixed:
      return text;
    case TextType::Fancy:
      return left_bracket + text + right_bracket;
    default:
      return "UNKNOWN TYPE";
  }
}

void AltText::append(const string& extra) {
  switch(type) {
    case TextType::Plain:
      text += extra;
      break;
    case TextType::Fancy:
      text += connector + extra;
      break;
    case TextType::Fixed:
      break;
  }
}