#include <iostream>
#include <string>
using namespace std;

class Student {
	private:
		string name;
		string bornDate;
		double testMark;
		double diplomaMark;
		double mathMark;
		double rating;
	public:
 		Student() {	// Конструктор по подразбиране
			name = "";
			bornDate = "";
			testMark = 0;
			diplomaMark = 0;
			mathMark = 0;
			rating = 0;
		}

		void setName(string aName) { name = aName; }
		void setBornDate(string aBornDate) { bornDate = aBornDate; }
		void setTestMark(double aTestMark) { testMark = aTestMark; }
		void setDiplomaMark(double aDiplomaMark) { diplomaMark = aDiplomaMark; }
		void setMathMark(double aMathMark) { mathMark = aMathMark; }

		string getName() { return name; }
		string getBornDate() { return bornDate; }
		double getTestMark() { return testMark; }
		double getDiplomaMark() { return diplomaMark; }
		double getMathMark() { return mathMark; }
		double getRating() { return testMark + diplomaMark + 2*mathMark; }
		
		void enterData() {
			cout << "\nName:";	cin >> name;
			cout << "Born date:";	cin >> bornDate;

			do { cout << "Test mark:";	cin >> testMark; }
			while(testMark < 2 || testMark > 6);

			do { cout << "Diploma mark:";	cin >> diplomaMark; }
			while(diplomaMark < 2 || diplomaMark > 6);

			do { cout << "Math mark:";	cin >> mathMark; }
			while(mathMark < 2 || mathMark > 6);
		}

		void printStudent() {
			cout << "Name: " << name << "\n";
			cout << "Born date: " << bornDate << "\n";
			cout << "Test mark: " << testMark << "\n";
			cout << "Diploma mark: " << diplomaMark << "\n";
			cout << "Math mark: " << mathMark << "\n";
			cout << "Rating: " << getRating() << "\n\n";
		}
};

void sort(Student* students, int n) {
	for(int i = 0; i < n-1; i++) {
		double maxRating = students[i].getRating();
		int maxIndex = i;
		for(int j = i; j < n; j++)
			if(students[j].getRating() > maxRating) {
				maxRating = students[j].getRating();
				maxIndex = j;
			}

		// Разменяме местата на студентите с индекси i и maxIndex
		Student temp;
		temp.setName(students[i].getName());
		temp.setBornDate(students[i].getBornDate());
		temp.setTestMark(students[i].getTestMark());
		temp.setDiplomaMark(students[i].getDiplomaMark());
		temp.setMathMark(students[i].getMathMark());

		students[i].setName(students[maxIndex].getName());
		students[i].setBornDate(students[maxIndex].getBornDate());
		students[i].setTestMark(students[maxIndex].getTestMark());
		students[i].setDiplomaMark(students[maxIndex].getDiplomaMark());
		students[i].setMathMark(students[maxIndex].getMathMark());

		students[maxIndex].setName(temp.getName());
		students[maxIndex].setBornDate(temp.getBornDate());
		students[maxIndex].setTestMark(temp.getTestMark());
		students[maxIndex].setDiplomaMark(temp.getDiplomaMark());
		students[maxIndex].setMathMark(temp.getMathMark());
	}
}

int main() {
	int n;
	do {
		cout << "\nEnter 3<=N<=600:";
		cin >> n;
	} while (n < 3 || n >600);

	Student* students = new Student[n];	// Заделяме памет за n на брой ученика
	for(int i = 0; i < n; i++) {
		students[i].enterData();
	}

	sort(students, n);		// Сортираме по бал, низходящо

	int k;
	do {
		cout << "\nEnter 25<K<31:";
		cin >> k;
	} while (k < 26 || k >30);

	cout << "\nAccepted students:\n";

	// Отпечатваме първите k на брой ученици, сортирани по бал в низходящ ред
	for(int i = 0; i < k && i < n; i++) students[i].printStudent();

	int lastAccepted = 0;
	// Извеждаме останалите ученици, на които балът е равен на бала на последния редовно приет ученик
	for(int i = k; i < n && students[i].getRating() == students[k].getRating(); i++) {
		students[i].printStudent();
		lastAccepted = i;
	}

	cout << "\nTen reserves:\n";
	// Извеждаме първите 10 резерви
	for(int i = 1; i <= 10; i++) {
		if(lastAccepted + i >= n) break;	// Учениците са свършили
		students[lastAccepted + i].printStudent();
	}

	delete[] students;		// Освобождаваме паметта за динамичния масив
	
	return 0;
}
