// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 100
// Output: 25

// Test case 2
// Input: 60
// Output: 15

// Test case 3
// Input: 40
// Output: 5

#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int a;
	int max = 0;
	cout << "Vui long nhap n nguyen duong: ";
	cin >> a;
	for (int i = 1; i <= a; i += 2) {
		if (a % i == 0) {
			max = i;
		}
	}
	cout << max;

	return 0;
}