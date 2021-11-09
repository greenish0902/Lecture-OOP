#include <iostream>
#include <cstdlib>

using namespace std;

class SimpleRational {
private:
  int numerator;
  int denominator;

public:
  SimpleRational(int n, int d): numerator(n), denominator(d) {
    if (d == 0) {
      cout << "Zero denominator error" << endl;
      exit(1);
    }
  }

  SimpleRational(): numerator(0), denominator(1) {}

  void set_numerator(int n) {
    numerator = n;
  }

  void set_denominator(int d) {
    if (d != 0) {
      denominator = d;
    } else {
      cout << "Zero denominator error" << endl;
      exit(1);
    }
  }

  int get_numerator() {
    return numerator;
  }
  
  int get_denominator() {
    return denominator;
  }
};

SimpleRational multiply(SimpleRational f1, SimpleRational f2) {
  return {f1.get_numerator() * f2.get_numerator(), f1.get_denominator() * f2.get_denominator()};
}

void print_fraction(SimpleRational f) {
  cout << f.get_numerator() << "/" << f.get_denominator();
}

int main() {
  SimpleRational fract(1, 2);
  cout << "The fraction is ";
  print_fraction(fract);
  cout << endl;
  fract.set_numerator(19);
  fract.set_denominator(4);
  cout << "The fraction now is ";
  print_fraction(fract);
  cout << endl;

  SimpleRational fract1{1, 2}, fract2{2, 3};
  auto prod = multiply(fract1, fract2);
  cout << "The product of ";
  print_fraction(fract1);
  cout << " and ";
  print_fraction(fract2);
  cout << " is ";
  print_fraction(prod);
  cout << endl;
}