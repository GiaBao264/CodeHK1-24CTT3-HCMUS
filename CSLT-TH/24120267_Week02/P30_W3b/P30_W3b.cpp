// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 6
// Output: la so hoan thien

// Test case 2
// Input: 9
// Output: khong la so hoan thien

// Test case 3
// Input: 28
// Output: la so hoan thien

#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int a;
	int tong = 0;
	cout << "Vui long nhap n nguyen duong: ";
	cin >> a;
	for (int i = 1; i < a; ++i) {
		if (a % i == 0) {
			tong += i;
		}
	}
	if (a == tong) {
		cout << a << " la so hoan thien";
	}
	else {
		cout << a << " khong la so hoan thien";
	}

	return 0;
}