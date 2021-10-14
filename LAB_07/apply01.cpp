#include <iostream>
#include <string>

using namespace std;

void getAddress(string& city, string& area, string& street, string& building) {
  cout << "시 : ";
  cin >> city;
  cout << "구 : ";
  cin >> area;
  cout << "로 : ";
  cin >> street;
  cout << "건물명 : ";
  cin >> building;
}

int main() {
  string city, area, street, building;
  getAddress(city, area, street, building);
  cout << endl << "집 주소 : " << city + area + street + building << endl;
}