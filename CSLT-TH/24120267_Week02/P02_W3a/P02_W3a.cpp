// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 5 3
// Output: 5 

// Test case 2
// Input: 7 4
// Output: 7

// Test case 3
// Input: 10 2
// Output: 10

#include <iostream>

using namespace std;

int main() {
	int a, b;
	cout << "Vui long nhap 2 so nguyen duong: ";
	cin >> a >> b;

	if (a >= b) {
		cout << a;
	}
	else {
		cout << b;
	}
	return 0;
}