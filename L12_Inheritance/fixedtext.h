#ifndef FIXEDTEXT_H_INCLUDED
#define FIXEDTEXT_H_INCLUDED

#include <string>
#include "text.h"

class FixedText: public Text {
public:
  FixedText();
  void append(const string&) override;
};

#endif