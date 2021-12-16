#include <iostream>

using namespace std;

class Train {
public:
  Train();
  Train(int people);
  ~Train();
  virtual int station(int takeOff, int takeOn);
protected:
  int mPeople;
};

class Ktx : public Train {
public:
  Ktx();
  Ktx(int people);
  ~Ktx();
  int station(int takeOff, int takeOn) override;
  int getPeople();
};

Train::Train(): mPeople(0) {}
Train::Train(int people) : mPeople(people) {}
Train::~Train() {}
int Train::station(int takeOff, int takeOn) {
  mPeople -= takeOff;
  mPeople += takeOn;
  return mPeople;
}
Ktx::Ktx(): Train(0) {}
Ktx::Ktx(int people): Train(people) {}
Ktx::~Ktx() {}
int Ktx::station(int takeOff, int takeOn) {
  int sum = getPeople();
  sum -= takeOff;
  sum += takeOn;
  if (sum < 0) {
    cout << "정원미달입니다" << endl;
  } else if (sum > 300) {
    cout << "정원초과입니다" << endl;
  } else {
    mPeople = sum;
  }
  return sum;
}
int Ktx::getPeople() {
  return mPeople;
}

int main() {
  Ktx k;
  int sum = 0, now = 0, max = -1000, station = 1;
  while (true) {
    int takeOff, takeOn;
    cout << station << "번역: ";
    cin >> takeOff >> takeOn;
    now = k.station(takeOff, takeOn);
    if ((now < 0) || (now > 300)) {
      break;
    }
    if (now > max) {
      max = now;
    }
    station++;
    if (station > 5) {
      cout << "가장 많은 사람이 탑승했을 때의 사람 수: " << max << endl;
      break;
    }
  }
  return 0;
}