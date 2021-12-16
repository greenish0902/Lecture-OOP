#include <iostream>

using namespace std;

class Polygon {
public:
  Polygon(): mPoint(0), mLength(0) {}
  Polygon(int point, float length): mPoint(point), mLength(length) {}
  ~Polygon() {}
  virtual void calcPerimeter() {
    cout << "Perimeter: ";
    if ((mPoint == 0) || (mLength == 0)) {
      cout << "empty";
    } else {
      cout << mPoint * mLength;
    }
    cout << endl;
  }
  virtual void calcArea() {
    cout << "Area: ";
    if ((mPoint == 0) || (mLength == 0)) {
      cout << "empty";
    }
    cout << endl;
  }
protected:
  int mPoint;
  double mLength;
};

class Rectangle: public Polygon {
public:
  Rectangle() {}
  Rectangle(int point, float length): Polygon(point, length) {}
  ~Rectangle() {}
  void calcPerimeter() override {
    cout << "Perimeter: ";
    if ((mPoint == 0) || (mLength == 0)) {
      cout << "empty";
    } else {
      cout << mPoint * mLength;
    }
    cout << endl;
  }
  void calcArea() override {
    cout << "Area: ";
    if ((mPoint == 0) || (mLength == 0)) {
      cout << "empty";
    } else {
      cout << (mLength * mLength);
    }
    cout << endl;
  }
};

int main() {
  Polygon pol;
  Rectangle rec(4, 10);

  cout << "--- Polygon class ---" << endl;
  pol.calcPerimeter();
  pol.calcArea();
  cout<< "--- Rectangle class ---" << endl;
  rec.calcPerimeter();
  rec.calcArea();

  return 0;
}