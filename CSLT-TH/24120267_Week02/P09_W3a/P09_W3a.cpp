// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 2 -7 5
// Output: x1 = 1, x2 = 2.5

// Test case 2
// Input: 3 4 1
// Output: x1 = -1, x2 = -0.33

// Test case 3
// Input: 1 1 1
// Output: Vo nghiem

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
	double a, b, c, delta;
	cout << "Vui long 3 so thuc a, b, c (ax^2 + bx + c): ";
	cin >> a >> b >> c;

	if (a != 0) {
		delta = pow(b, 2) - 4 * a * c;
		if (delta > 0) {
			cout << "x1 = " << setprecision(2) << (-b - sqrt(delta)) / (2 * a) << endl;
			cout << "x2 = " << setprecision(2) << (-b + sqrt(delta)) / (2 * a);
		}
		else if (delta == 0) {
			cout << "x1 = x2 = " << setprecision(2) << -b / (2 * a);
		}
		else {
			cout << "Vo nghiem";
		}
	}
	else {
		cout << "Nhap a khac 0.";
	}
	

	return 0;
}