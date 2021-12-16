#include <iostream>
#include <cmath>

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
      cout << (mPoint * mLength);
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

class Triangle: public Polygon {
public:
  Triangle() {}
  Triangle(int point, float length): Polygon(point, length) {}
  ~Triangle() {}
  void calcArea() override {
    double PI = 3.1415926;
    cout << "Area: ";
    if ((mPoint == 0) || (mLength == 0)) {
      cout << "empty";
    } else {
      cout << (mLength * mLength * tan(PI / 3) / 4);
    }
    cout << endl;
  }
};

class Rectangle: public Polygon {
public:
  Rectangle() {}
  Rectangle(int point, float length): Polygon(point, length) {}
  ~Rectangle() {}
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

class Circle: public Polygon {
public:
  Circle() {}
  Circle(int point, float length): Polygon(point, length) {}
  ~Circle() {}
  void calcPerimeter() override {
    cout << "Perimeter: ";
    if (mLength == 0) {
      cout << "empty";
    } else {
      cout << (2 * 3.14 * mLength);
    }
    cout << endl;
  }
  void calcArea() override {
    cout << "Area: ";
    if (mLength == 0) {
      cout << "empty";
    } else {
      cout << (mLength * mLength * 3.14);
    }
    cout << endl;
  }
};

int main() {
  Triangle tri(3, 10);
  Rectangle rec(4, 10);
  Circle cir(0, 5);

	cout << "--- Triangle class ---" << endl;
	tri.calcPerimeter();
	tri.calcArea();
	cout << "--- Rectangle class ---" << endl;
	rec.calcPerimeter();
	rec.calcArea();
	cout << "--- Circle class ---" << endl;
	cir.calcPerimeter();
	cir.calcArea();

	return 0;
}