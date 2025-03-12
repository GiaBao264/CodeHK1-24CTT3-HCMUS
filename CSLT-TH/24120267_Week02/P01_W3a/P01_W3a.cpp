// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 5 3
// Output: 3

// Test case 2
// Input: 7 4
// Output: 4

// Test case 3
// Input: 10 2
// Output: 2

#include <iostream>

using namespace std;

int main() {
	int a, b;
	cout << "Vui long nhap 2 so nguyen duong: ";
	cin >> a >> b;

	if (a >= b) {
		cout << b;
	}
	else {
		cout << a;
	}
	return 0;
}