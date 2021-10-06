#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool getStu (ifstream& stuFile, int& stuID, int& exam1, int& exam2, int& final);
void writeStu (ofstream& gradesFile, int stuID, int avrg, char grade);
void calcGrade (int exam1, int exam2, int final, int& avrg, char& grade);

int main() {
  ifstream stuFile;
  cout << "Begin student grades\n";
  stuFile.open("ch7STUFL.DAT");
  if (!stuFile) {
    cerr << "\aError opening student file\n";
    exit (100);
  }
  ofstream gradesFile;
  gradesFile.open("ch7STUGR.DAT");
  if (!gradesFile) {
    cerr << "\aError opening grades file\n";
    exit (102);
  }

  int stuID;
  int exam1;
  int exam2;
  int final;
  int avrg;
  char grade;

  while (getStu(stuFile, stuID, exam1, exam2, final)) {
    calcGrade(exam1, exam2, final, avrg, grade);
    writeStu(gradesFile, stuID, avrg, grade);
  }

  stuFile.close();
  gradesFile.close();
  cout << "End student grades\n";
  return 0;
}

bool getStu(ifstream& stuFile, int& stuID, int& exam1, int& exam2, int& final) {
  stuFile >> stuID >> exam1 >> exam2 >> final;
  if (!stuFile) {
    return false;
  }
  return true;
}

void calcGrade(int exam1, int exam2, int final, int& avrg, char& grade) {
  avrg = (exam1 + exam2 + final) / 3;
  if (avrg >= 90) {
    grade = 'A';
  } else if (avrg >= 80) {
    grade = 'B';
  } else if (avrg >= 70) {
    grade = 'C';
  } else if (avrg >= 60) {
    grade = 'D';
  } else {
    grade = 'F';
  }
  return;
}

void writeStu (ofstream& gradesFile, int stuID, int avrg, char grade) {
  gradesFile.fill('0');
  gradesFile << setw(4) << stuID;
  gradesFile.fill(' ');
  gradesFile << setw(3) << avrg;
  gradesFile << ' ' << grade << endl;
  return;
}