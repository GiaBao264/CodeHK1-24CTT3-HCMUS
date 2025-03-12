// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 2 3
// Output: 84.00

// Test case 2
// Input: 4 5
// Output: 1118480.00

// Test case 3
// Input: 6 7
// Output: 80603140212.00

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
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i * 2; ++j) {
			tich *= x;
		}
		tong += tich;
		tich = 1;
	}
	cout << tong;
	return 0;
}