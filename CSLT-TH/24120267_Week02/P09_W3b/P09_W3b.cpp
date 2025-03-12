// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 5
// Output: 120

// Test case 2
// Input: 6
// Output: 720

// Test case 3
// Input: 7
// Output: 5040

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
	int a;
	cout << "Vui long nhap n khong am: ";
	cin >> a;
	cout << fixed << setprecision(2);
	int tich = 1;
	for (int i = 1; i <= a; ++i) {
		tich *= i;
	}
	cout << tich;

	return 0;
}