// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 6
// Output: 4

// Test case 2
// Input: 5
// Output: 2

// Test case 3
// Input: 4
// Output: 3

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
	int n;
	cout << "Vui long nhap n: ";
	cin >> n;
	cout << fixed << setprecision(2);
	int dem = 0;
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) {
			dem++;
		}
	}
	cout << dem;
	return 0;
}