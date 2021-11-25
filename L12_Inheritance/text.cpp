#include "text.h"

Text::Text(const string &t): text(t) {}

string Text::get() const {
  return text;
}

void Text::append(const string& extra) {
  text += extra;
}