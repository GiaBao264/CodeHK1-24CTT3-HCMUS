// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 2 3
// Output: 8.00

// Test case 2
// Input: 3 4
// Output: 81.00

// Test case 3
// Input: 7 8
// Output: 5764801.00

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
	for (int i = 1; i <= n; ++i) {
		tich *= x;
	}
	cout << tich;

	return 0;
}