// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 2 1
// Output: -0.5

// Test case 2
// Input: 3 6
// Output: -2

// Test case 3
// Input: 10 5
// Output: -0.5

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double a, b;
	cout << "Vui long 2 so thuc a, b (ax + b): ";
	cin >> a >> b;

	cout << "x = " << setprecision(2) << -b / a;

	return 0;
}