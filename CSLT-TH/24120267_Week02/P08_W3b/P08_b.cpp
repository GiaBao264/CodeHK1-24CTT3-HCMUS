// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 5
// Output: 4.78

// Test case 2
// Input: 6
// Output: 5.70

// Test case 3
// Input: 7
// Output: 6.64

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
	int a;
	cout << "Vui long nhap n khong am: ";
	cin >> a;
	cout << fixed << setprecision(2);
	double sum = 0;
	for (int i = 0; i <= a; ++i) {
		sum += (2.0 * i + 1.0) / (2.0 * i + 2.0);
	}
	cout << sum;

	return 0;
}