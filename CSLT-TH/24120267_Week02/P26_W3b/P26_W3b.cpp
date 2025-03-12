// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 6
// Output: 3

// Test case 2
// Input: 7
// Output: 7

// Test case 3
// Input: 4
// Output: 1

#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int a;
	int tich = 1;
	cout << "Vui long nhap n nguyen duong: ";
	cin >> a;
	for (int i = 1; i <= a; i += 2) {
		if (a % i == 0) {
			tich *= i;
		}
	}
	cout << tich;

	return 0;
}