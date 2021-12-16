#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
  int x;
  int y;
public:
  Point();
  ~Point();
  Point(int, int);
  int getX() const;
  int getY() const;
  void setX(int);
  void setY(int);
  void setPoint(int x, int y);
  Point operator-(const Point&);
  Point operator*(const Point&);
  Point operator=(const Point&);
};

Point::Point(): x(0), y(0) { }
Point::~Point() { }
Point::Point(int _x, int _y) {
  this->x = _x;
  this->y = _y;
}
int Point::getX() const { return this->x; }
int Point::getY() const { return this->y; }
void Point::setX(int _x) { this->x = _x; }
void Point::setY(int _y) { this->y = _y; }
void Point::setPoint(int x, int y) {
  this->x = x;
  this->y = y;
}
Point Point::operator-(const Point& pt) {
  Point result(this->x - pt.getX(), this->y - pt.getY());
  return result;
}
Point Point::operator*(const Point& pt) {
  Point result(this->x * pt.getX(), this->y * pt.getY());
  return result;
}
Point Point::operator=(const Point& pt) {
  this->x = pt.getX();
  this->y = pt.getY();
  return *this;
}

int main() {
  int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  Point *pP1, *pP2, *pP3;

	cout << "첫번째 좌표(x1, y1)를 입력하세요 : ";
	cin >> x1 >> y1;

	cout << "두번째 좌표(x2, y2)를 입력하세요 : ";
	cin >> x2 >> y2;

	pP1 = new Point(x1, y1);
	pP2 = new Point(x2, y2);
	pP3 = new Point();

	// pP1->setPoint(x1, y1);
	// pP2->setPoint(x2, y2);

  *pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);

	cout << "두 좌표 사이의 길이는 " << sqrt(pP3->getX() + pP3->getY()) << "입니다." << endl;

	return 0;
}