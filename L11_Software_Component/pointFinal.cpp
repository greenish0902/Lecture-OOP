#include <iostream>

using namespace std;

class Point {
private:
  double x;
  double y;
  static int countCreatedObjects;

public:
  Point();
  Point(int x, int y);
  ~Point();
  void setPoint(int x, int y);
  int getX() const;
  int getY() const;
  static int getCreatedObject();
  Point operator+(const Point& point);
  Point& operator=(const Point& point);
  friend ostream& operator<<(ostream& os, const Point& point);
  friend class SpyPoint;
};

int Point::countCreatedObjects = 0;

Point::Point() {
  cout << "constructor Point() invoked..." << endl;
  x = y = 0;
  countCreatedObjects++;
}

Point::~Point() {
  cout << "(" << this->x << ", " << this->y << ") destructor invoked..." << endl;
}

Point::Point(int x, int y) {
  this->x = x;
  this->y = y;
  countCreatedObjects++;
}

void Point::setPoint(int x, int y) {
  this->x = x;
  this->y = y;
}

int Point::getX() const {
  return this->x;
}
int Point::getY() const{
  return this->y;
}
int Point::getCreatedObject() {
  return countCreatedObjects;
}

Point Point::operator+(const Point& point) {
  Point result(this->x + point.getX(), this->y + point.getY());
  return result;
}

Point& Point::operator=(const Point& point) {
  this->x = point.getX();
  this->y = point.getY();
  return *this;
}

ostream& operator<<(ostream& os, const Point& point) {
  return os << "(" << point.getX() << ", " << point.getY() << ")";
}

class SpyPoint {
public:
  void printPoint(const Point& point);
};

void SpyPoint::printPoint(const Point& point) {
  cout << "{X: " << point.x << "}" << " {Y: " << point.y << "}" << endl;
}

int main() {
  Point *pP1, *pP2;
  SpyPoint SP;

  cout << "Number of created object is : " << Point::getCreatedObject() << endl << endl;

  pP1 = new Point;
  pP2 = new Point(1, 2);

  pP1->setPoint(10, 20);
  *pP2 = *pP1 + *pP2;

  cout << "[X : " << pP1->getX() << "], " << "[Y : " << pP1->getY() << "]" << endl;
  cout << *pP2 << endl << endl;
  
  cout << "Number of created object is : " << Point::getCreatedObject() << endl;

  SP.printPoint(*pP1);
  SP.printPoint(*pP2);

  delete pP1;
  delete pP2;
}