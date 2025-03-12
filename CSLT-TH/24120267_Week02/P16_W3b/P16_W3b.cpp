// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 2 3
// Output: 4.67

// Test case 2
// Input: 1 2
// Output: 1.33

// Test case 3
// Input: 3 4
// Output: 18.60

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
	double mau = 0.0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			tich *= x;
		}
		for (int k = 1; k <= i; ++k) {
			mau += k;
		}
		tong = tong + (tich / mau);
		tich = 1;
		mau = 0;
	}
	cout << tong;
	return 0;
}