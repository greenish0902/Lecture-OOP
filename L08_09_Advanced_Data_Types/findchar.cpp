#include <iostream>

using namespace std;

bool find_char(const char *s, char ch) {
  while (*s != '\0') {
    if (*s == ch) {
      return true;
    }
    s++;
  }
  return false;
}

int main() {
  const char *phrase = "this is a phrase";
  for (char ch = 'a'; ch <= 'z'; ch++) {
    cout << '\'' << ch << '\'' << " is ";
    if (!find_char(phrase, ch)) {
      cout << "NOT ";
    }
    cout << "in " << '\"' << phrase << '\"' << '\n';
  }
}