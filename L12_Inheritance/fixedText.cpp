#include "fixedtext.h"

FixedText::FixedText(): Text("FIXED") {}

void FixedText::append(const string&) {
  // Disallow concatenation
}