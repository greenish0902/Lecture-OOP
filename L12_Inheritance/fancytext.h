#ifndef FANCYTEXT_H_INCLUDED
#define FANCYTEXT_H_INCLUDED

#include <string>
#include "text.h"

class FancyText: public Text {
private:
  string left_bracket;
  string right_bracket;
  string connector;
public:
  FancyText(const string& t, const string& left, const string& right, const string& conn);
  string get() const override;
  void append(const string& extra) override;
};

#endif