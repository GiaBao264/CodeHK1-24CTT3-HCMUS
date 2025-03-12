// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 9.0
// Output: A

// Test case 2
// Input: 8.5
// Output: A

// Test case 3
// Input: 4.5
// Output: F

#include <iostream>

using namespace std;

int main() {
	double a;
	cout << "Vui long diem trung binh: ";
	cin >> a;

	if (8.5 <= a && a <= 10) {
		cout << "A";
	}
	else if (7 <= a && a < 8.7) {
		cout << "B";
	}
	else if (5.5 <= a && a < 7) {
		cout << "C";
	}
	else if (4 <= a && a < 5.5) {
		cout << "D";
	}
	else {
		cout << "F";
	}

	return 0;
}