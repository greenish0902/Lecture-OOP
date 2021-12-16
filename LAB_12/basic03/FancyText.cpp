#include "FancyText.h"

FancyText::FancyText(string _t, string _lb, string _rb, string _con) : 
  Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con) {}
string FancyText::get() const { return left_brac + Text::get() + connector + right_brac; };
void FancyText::append(string _extra) { connector += _extra; };