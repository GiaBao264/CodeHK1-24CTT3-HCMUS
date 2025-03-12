// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 8 21
// Output: 80.000

// Test case 2
// Input: 3 21
// Output: 50.000

// Test case 3
// Input: 2 15
// Output: 60.000

#include <iostream>

using namespace std;

int main() {
	int a, b;
	cout << "Vui long nhap thu trong tuan, gio: ";
	cin >> a >> b;

	if (b < 0 || b > 23 || a > 8 || a < 2) {
		cout << "Khong hop le";
		return 0;
	}

	if (a == 2 || a == 4 || a == 5) {
		if (b < 17) {
			cout << "60.000";
		}
		else {
			cout << "70.000";
		}
	}
	else if (a == 6 || a == 7 || a == 8) {
		if (b < 17) {
			cout << "75.000";
		}
		else {
			cout << "80.000";
		}
	}
	else {
		cout << "50.000";
	}

	return 0;
}