// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 6
// Output: 8

// Test case 2
// Input: 4
// Output: 6

// Test case 3
// Input: 2
// Output: 2

#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int a;
	int tong = 0;
	cout << "Vui long nhap n nguyen duong: ";
	cin >> a;
	for (int i = 2; i <= a; i += 2) {
		if (a % i == 0) {
			tong += i;
		}
	}
	cout << tong;

	return 0;
}