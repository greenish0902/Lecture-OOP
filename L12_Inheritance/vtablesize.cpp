#include <iostream>

using namespace std;

class NoVTable {
  int data;
public:
  void set(int d) { data = d; }
  int get() { return data; }
};

class HasVTable {
  int data;
public: 
  virtual void set(int d) { data = d; }
  virtual int get() { return data; }
};

int main() {
  NoVTable no_vtable;
  HasVTable has_vtable;
  no_vtable.set(10);
  has_vtable.set(10);
  cout << "no_vtable size = " << sizeof no_vtable << endl;
  cout << "has_vtable size = " << sizeof has_vtable << endl;
}