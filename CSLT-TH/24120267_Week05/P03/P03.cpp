#include "header.h"

string month[15] = { "0", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int main() {
	FILE* input;
	FILE* output;
	FILE* k19;
	FILE* findID;
	FILE* findName;
	FILE* sortID;
	FILE* sortName;
	FILE* sortGPA;
	FILE* sortDOB;

	if (freopen_s(&input, "input.txt", "r", stdin) != 0) {
		cerr << "Khong the mo file." << endl;
		return 1;
	}
	if (freopen_s(&output, "output.txt", "w", stdout) != 0) {
		cerr << "Khong the xuat file." << endl;
		return 1;
	}

	Course course;

	inputCourse(course);

	outputCourse(course);
	
	Student newStu = { "S004", "John Doe", 15, 8, 2002, 3.5 };
	if (addStudent(course, newStu)) {
		cout << "Added student " << newStu.name << endl;
	}
	else {
		cout << "Cannot add " << newStu.name << endl;
	}

	string removeID = "S002";
	if (removeStudent(course, removeID)) {
		cout << "Student have " << removeID << " has been removed" << endl;
	}
	else {
		cout << "Cannot remove " << removeID << endl;
	}

	time_t t = time(0);
	tm now;
	localtime_s(&now, &t);
	int currentDay = now.tm_mday;
	int currentMonth = now.tm_mon + 1;
	int currentYear = now.tm_year + 1900;

	cout << "Students born in " << month[currentMonth] << " : ";
	findStudent1(course, currentMonth);
	cout << endl;

	cout << "Students born in " << currentDay << "/" << month[currentMonth] << " : ";
	findStudent2(course, currentDay, currentMonth);
	cout << endl;

	cout << "Students have driving licences: ";
	findStudent3(course, currentDay, currentMonth, currentYear);
	cout << endl;



	fclose(input);
	fclose(output);

	if (freopen_s(&k19, "k19.txt", "w", stdout) != 0) {
		cerr << "Khong the xuat file." << endl;
		return 1;
	}
	k19Stu(course);
	fclose(k19);

	if (freopen_s(&findID, "findID.txt", "w", stdout) != 0) {
		cerr << "Khong the xuat file." << endl;
		return 1;
	}
	string ID = { "1901" };
	scanID(course, ID);
	fclose(findID);

	if (freopen_s(&findName, "findName.txt", "w", stdout) != 0) {
		cerr << "Khong the xuat file." << endl;
		return 1;
	}
	string Name = { "Gia" };
	scanName(course, Name);
	fclose(findName);

	if (freopen_s(&sortID, "sortID.txt", "w", stdout) != 0) {
		cerr << "Khong the xuat file." << endl;
		return 1;
	}
	sortByID(course);
	fclose(sortID);

	if (freopen_s(&sortName, "sortName.txt", "w", stdout) != 0) {
		cerr << "Khong the xuat file." << endl;
		return 1;
	}
	sortByName(course);
	fclose(sortName);

	if (freopen_s(&sortGPA, "sortGPA.txt", "w", stdout) != 0) {
		cerr << "Khong the xuat file." << endl;
		return 1;
	}
	sortByGPA(course);
	fclose(sortGPA);

	if (freopen_s(&sortDOB, "sortDOB.txt", "w", stdout) != 0) {
		cerr << "Khong the xuat file." << endl;
		return 1;
	}
	sortByDOB(course);
	fclose(sortDOB);

	return 0 ^ 0;
}