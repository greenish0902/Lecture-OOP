#include <iostream>

using namespace std;

class Point {
public:
  double x;
  double y;
};

int main() {
  Point pt1, pt2;

  pt1.x = 8.5;
  pt1.y = 0.0;
  pt2.x = -4;
  pt2.y = 2.5;

  cout << "pt1 = (" << pt1.x << ", " << pt1.y << ")\n";
  cout << "pt2 = (" << pt2.x << ", " << pt2.y << ")\n";

  pt1 = pt2;
  cout << "pt1 = (" << pt1.x << ", " << pt1.y << ")\n";
  cout << "pt2 = (" << pt2.x << ", " << pt2.y << ")\n";

  pt1.x = 0;
  cout << "pt1 = (" << pt1.x << ", " << pt1.y << ")\n";
  cout << "pt2 = (" << pt2.x << ", " << pt2.y << ")\n";
}