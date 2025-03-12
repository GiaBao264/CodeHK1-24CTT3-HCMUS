// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 1 2019
// Output: 31

// Test case 2
// Input: 2 2019
// Output: 28

// Test case 3
// Input: 2 2020
// Output: 29

#include <iostream>

using namespace std;

int main() {
	int a, b;
	cout << "Vui long nhap thang, nam: ";
	cin >> a >> b;

	if (a >= 1 && a <= 12 && b > 0) {
		if (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12) {
			cout << "31";
		}
		else if (a == 4 || a == 6 || a == 9 || a == 11) {
			cout << "30";
		}
		else {
			if (b % 4 == 0 && b % 100 != 0 || b % 400 == 0) {
				cout << "29";
			}
			else {
				cout << "28";
			}
		}
	}

	return 0;
}