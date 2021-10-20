#include <iostream>
#include <vector>

using namespace std;

int inputGrade(float grade) {
  cin >> grade;
  if ((grade - (int)grade) != 0.0 || grade < 0 || grade > 100) {
    cout << "invalid input!!!" << endl;
    exit(EXIT_FAILURE);
  }
  else {
    return (int)grade;
  }
}

int max;

int* topGrade(const vector<int>& grade) {
  int maxIdx = 0;
  for (int i = 0; i < grade.size(); i++) {
    if (grade[i] > grade[maxIdx]) {
      maxIdx = i;
    }
  }
  return (int*)&(grade[maxIdx]);
}

int main() {
  vector<int> grades;
  float _grade = 0;
  for (int i = 0; i < 3; i++) {
    cout << "input " << i << "-th grade(0~100): ";
    int grade = inputGrade(_grade);
    grades.push_back(grade);
  }
  cout << "Top Grade:  " << *topGrade(grades) << endl;
  return 0;
}