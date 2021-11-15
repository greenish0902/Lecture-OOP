#include <iostream>
#include <vector>

using namespace std;

class Student {
private:
  string name, dept;
  int id;
  vector<string> subjects;
  vector<char> grades;

public:
  Student(): name("default"), id(0), dept("depart") {}
  Student(string _name, int _id, string _dept): name(_name), id(_id), dept(_dept) {}
  
  void setName(string _name) {
    name = _name;
  }
  void setID(int _id) {
    id = _id;
  }
  void setDpt(string _dept) {
    dept = _dept;
  }
  void print() {
    cout << name << " " << id << " " << dept << endl;
  }

  void addGrade(string subject, char grade) {
    subjects.push_back(subject);
    grades.push_back(grade);
  }

  void printGrades() {
    for (int i = 0; i < subjects.size(); i++) {
      cout << subjects[i] << " " << grades[i] << endl;
    }
    getGPA();
  }

  void getGPA() {
    float gpa = 0;
    for (char elem : grades) {
      switch(elem) {
        case 'A':
          gpa += 4.0;
          break;
        case 'B':
          gpa += 3.0;
          break;
        case 'C':
          gpa += 2.0;
          break;
        case 'D':
          gpa += 1.0;
          break;
        case 'F':
          gpa += 0.0;
          break;
      }
    }
    cout << "GPA : " << (gpa / grades.size());
  }

  void getYear(int year) {
    int term = (year - (id / 1000000));
    string grade = "";
    if (term < 1) {
      grade = "Freshman (1학년)";
    } else if (term < 2) {
      grade = "Sophomore (2학년)";
    } else if (term < 3) {
      grade = "Junior (3학년)";
    } else if (term < 4) {
      grade = "senior (4학년)";
    } else {
      grade = "About to graduate (5학년 이상)";
    }
    cout << grade << endl;
  }
};

int main() {
	Student Harry("Harry", 2017310973, "CS");
	Harry.print();
	Harry.getYear(2019);
	Harry.addGrade("programming", 'A');
	Harry.addGrade("Basic Circuit", 'B');
	Harry.printGrades();
	cout << "\n\n";

	Student Ron;
	Ron.print();
	cout << "\n";
	Ron.setName("Ron");
	Ron.setID(2014103959);
	Ron.setDpt("EE");
	Ron.print();
	Ron.getYear(2019);
	Ron.addGrade("Computer Architecture", 'B');
	Ron.addGrade("Maching Learning", 'B');
	Ron.addGrade("Computer Vision", 'C');
	Ron.printGrades();
	cout << "\n\n";

	return 0;
}