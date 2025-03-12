// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 9.0
// Output: Outstanding

// Test case 2
// Input: 8.5
// Output: Excellent

// Test case 3
// Input: 4.5
// Output: Below Average

#include <iostream>

using namespace std;

int main() {
	double a;
	cout << "Vui long diem trung binh: ";
	cin >> a;

	if (9 <= a && a <= 10) {
		cout << "Outstanding";
	}
	else if (8 <= a && a < 9) {
		cout << "Excellent";
	}
	else if (7 <= a && a < 8) {
		cout << "Good";
	}
	else if (6 <= a && a < 7) {
		cout << "Above Average";
	}
	else if (5 <= a && a < 6) {
		cout << "Average";
	}
	else {
		cout << "Below Average";
	}

	return 0;
}