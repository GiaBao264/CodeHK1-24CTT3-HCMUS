// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 2019
// Output: 2019 khong la nam nhuan

// Test case 2
// Input: 2020
// Output: 2020 la nam nhuan

// Test case 3
// Input: 1800
// Output: 1800 khong la nam nhuan

#include <iostream>

using namespace std;

int main() {
	int a;
	cout << "Vui long nhap nam: ";
	cin >> a;
	if (a % 4 == 0 && a % 100 != 0) {
		cout << a << " la nam nhuan";
	}
	else if (a % 400 == 0) {
		cout << a << " la nam nhuan";
	}
	else {
		cout << a << " khong la nam nhuan";
	}

	return 0;
}