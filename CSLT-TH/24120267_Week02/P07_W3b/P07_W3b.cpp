// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 5
// Output: 3.55

// Test case 2
// Input: 6
// Output: 4.41

// Test case 3
// Input: 7
// Output: 5.28

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
		sum += i / (i + 1.0);
	}
	cout << sum;

	return 0;
}