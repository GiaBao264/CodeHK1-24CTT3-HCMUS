// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 5
// Output: 15

// Test case 2
// Input: 10
// Output: 55

// Test case 3
// Input: 6
// Output: 21

#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int a;
	cout << "Vui long nhap n khong am: ";
	cin >> a;
	int sum = 0;
	for (int i = 1; i <= a; ++i) {
		sum += i;
	}
	cout << sum;

	return 0;
}