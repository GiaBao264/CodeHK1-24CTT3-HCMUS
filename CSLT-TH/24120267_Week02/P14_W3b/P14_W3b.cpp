// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 2 3
// Output: 170.00

// Test case 2
// Input: 1 2
// Output: 3.00

// Test case 3
// Input: 3 4
// Output: 22143.00

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
	double x;
	int n;
	cout << "Vui long nhap x, n: ";
	cin >> x >> n;
	cout << fixed << setprecision(2);
	double tich = 1.0;
	double tong = 0.0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 1; j <= ((i * 2) + 1); ++j) {
			tich *= x;
		}
		tong += tich;
		tich = 1;
	}
	cout << tong;
	return 0;
}