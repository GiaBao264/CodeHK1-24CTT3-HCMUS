// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 9
// Output: Nice

// Test case 2
// Input: 8
// Output: Eight

// Test case 3
// Input: 100
// Output: Unknown

#include <iostream>

using namespace std;

int main() {
	int a;
	cout << "Vui long so nguyen: ";
	cin >> a;

	if (a == 0) {
		cout << "Zero";
	}
	else if (a == 1) {
		cout << "One";
	}
	else if (a == 2) {
		cout << "Two";
	}
	else if (a == 3) {
		cout << "Three";
	}
	else if (a == 4) {
		cout << "Four";
	}
	else if (a == 5) {
		cout << "Five";
	}
	else if (a == 6) {
		cout << "Six";
	}
	else if (a == 7) {
		cout << "Seven";
	}
	else if (a == 8) {
		cout << "Eight";
	}
	else if (a == 9) {
		cout << "Nine";
	}
	else {
		cout << "Unknown";
	}

	return 0;
}