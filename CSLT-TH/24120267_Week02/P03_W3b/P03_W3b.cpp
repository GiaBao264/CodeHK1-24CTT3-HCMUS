// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 5
// Output: 2.28

// Test case 2
// Input: 6
// Output: 2.45

// Test case 3
// Input: 7
// Output: 2.59

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
	for (int i = 1; i <= a; ++i) {
		sum += 1.0/i;
	}
	cout << sum;

	return 0;
}