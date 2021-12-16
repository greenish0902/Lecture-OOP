#include <iostream>
#include <iomanip>
#include <functional>

using namespace std;

function<double(double)> derivative(function<double(double)> f, double h) {
  return [f, h] (double x) { return (f(x + h) - f(x)) / h; };
}

double fun(double x) {
  return 3 * x * x + 5;
}
double ans(double x) {
  return 6 * x;
}

int main() {
  double h = 0.0000001;
  auto der = derivative(fun, h);

  double x = 5.0;
  cout << "------------------------------------------------------" << endl;
  cout << "                                   Approx.    Actual " << endl;
  cout << "   x        f(x)          h         f\'(x)      f\'(x)" << endl;
  cout << "------------------------------------------------------" << endl;
  while (x < 5.1) {
    cout << fixed << showpoint << setprecision(5); 
    cout << x << " " << fun(x) << " " << h << " " << der(x) << "   " << ans(x) << '\n';
    x += 0.01;
  }
}