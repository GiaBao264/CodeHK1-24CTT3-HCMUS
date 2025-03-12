// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 5
// Output: 1 5

// Test case 2
// Input: 6
// Output: 1 2 3 6

// Test case 3
// Input: 7
// Output: 1 7

#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int a;
	cout << "Vui long nhap n nguyen duong: ";
	cin >> a;
	for (int i = 1; i <= a; ++i) {
		if (a % i == 0) {
			cout << i << " ";
		}
	}

	return 0;
}