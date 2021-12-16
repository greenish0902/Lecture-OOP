#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

template<typename T>
class CList {
private:
  T m_Array[5];
	int m_Length;
public:
	CList();
	~CList();

	bool IsEmpty();
	bool IsFull();

	void Add(T input);
	void Delete(T input);
	void Print();
};

template<typename T>
CList<T>::CList(): m_Length(0) {}
template<typename T>
CList<T>::~CList() {}
template<typename T>

bool CList<T>::IsEmpty() {
	if (m_Length == 0) {
		cout << " List is empty" << endl;
		return 1;
	} else {
		return 0;
	}
}
template<typename T>
bool CList<T>::IsFull() {
	if (m_Length == 5) {
		cout << " List is full" << endl;
		return 1;
	} else {
		return 0;
	}
}

template<typename T>
void CList<T>::Add(T input) {
	bool dup = false;
	if (!IsFull()) {
		for (auto iter = begin(m_Array); iter < end(m_Array); iter++) {
			if (*iter == input) {
				cout << "\t중복된 데이터가 존재합니다." << endl;
				dup = true;
				break;
			}
		}
		if (!dup) {
			m_Array[m_Length] = input;
			m_Length++;
			sort(m_Array, m_Array + m_Length);
		}
	}
}
template<typename T>
void CList<T>::Delete(T input) {
	int removeIdx;
	if (!IsEmpty()) {
		for (int i = 0; i < m_Length; i++) {
			if (m_Array[i] == input) {
				removeIdx = i;
			}
		}
		for (int j = removeIdx; j < m_Length; j++) {
			m_Array[j] = m_Array[j+1];
		}
		m_Length--;
	}
}
template<typename T>
void CList<T>::Print() {
	cout << "☃︎ Current List" << endl;
	for (auto iter = begin(m_Array); iter < begin(m_Array) + m_Length; iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

int command() {
	int num;
	cout << "\n\t---- menu ----" << endl;
	cout << "\t1. 리스트 추가" << endl;
	cout << "\t2. 리스트 삭제" << endl;
	cout << "\t3. 리스트 출력" << endl;
	cout << "\t4. 프로그램 종료" << endl;
	cout << "\n\t입력 --> ";
	cin >> num;
	return num;
}

int main() {
	CList<int> list;
	int input;
	int com;
	while (1)	{	
    com = command();
		switch (com) {
		case 1:
			cout << "\n추가할 데이터 : ";
			cin >> input;
			list.Add(input);
			break;
		case 2:
			cout << "\n삭제할 데이터 : ";
			cin >> input;
			list.Delete(input);
			break;
		case 3:
			list.Print();
			break;
		case 4:
			cout << "\n\t프로그램을 종료합니다\n";
			return 0;
			break;
		default:
			break;			
		}
	}
  return 0;
}