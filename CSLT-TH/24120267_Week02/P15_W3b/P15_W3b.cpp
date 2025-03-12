// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 5	
// Output: 1.67

// Test case 2
// Input: 6
// Output: 1.71

// Test case 3
// Input: 7
// Output: 1.75

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
	int n;
	cout << "Vui long nhap n: ";
	cin >> n;
	cout << fixed << setprecision(2);
	double mau = 0.0;
	double tong = 0.0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			mau += j;
		}
		tong += 1.0 / mau;
		mau = 0;
	}
	cout << tong;
	return 0;
}