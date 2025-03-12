#include "header.h"

int main() {
	FILE* input;
	FILE* output;
	FILE* output2;
	FILE* class19;
	FILE* compareID;
	FILE* compareGPA;
	FILE* compareName;
	FILE* comparefirstname;
	FILE* comparelastname;
	FILE* comparedob;

	if (freopen_s(&input, "input.txt", "r", stdin) != 0) {
		cerr << "Khong the mo file." << endl;
		return 1;
	}
	if (freopen_s(&output, "output.txt", "w", stdout) != 0) {
		cerr << "Khong the xuat file." << endl;
		return 1;
	}

	vector<Student> student;
	inputStudent(student);
	outputStudent(student);

	fclose(output);
	fclose(input);

	if (freopen_s(&output2, "output2.txt", "w", stdout) != 0) {
		cerr << "Khong the xuat file." << endl;
		return 1;
	}
	outputStudent2(student);
	fclose(output2);

	if (freopen_s(&class19, "class19.txt", "w", stdout) != 0) {
		cerr << "Khong the xuat file." << endl;
		return 1;
	}
	classK(student);
	fclose(class19);

	if (freopen_s(&compareID, "compareID.txt", "w", stdout) != 0) {
		cerr << "Khong the xuat file." << endl;
		return 1;
	}
	compareId(student);
	fclose(compareID);

	if (freopen_s(&compareGPA, "compareGPA.txt", "w", stdout) != 0) {
		cerr << "Khong the xuat file." << endl;
		return 1;
	}
	compareGpa(student);
	fclose(compareGPA);

	if (freopen_s(&compareName, "compareName.txt", "w", stdout) != 0) {
		cerr << "Khong the xuat file." << endl;
		return 1;
	}
	compareNAME(student);
	fclose(compareName);

	return 0;
}