// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 2 -7 5
// Output: x1 = -1.00, x2 = 1.00, x3 = -1.58, x4 = 1.58

// Test case 2
// Input: 3 4 1
// Output: Vo nghiem

// Test case 3
// Input: 1 1 1
// Output: Vo nghiem

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
	double a, b, c, delta;
	cout << "Vui long 3 so thuc a, b, c (ax^4 + bx^2 + c): ";
	cin >> a >> b >> c;

	cout << fixed << setprecision(2);
	if (a != 0) {
		delta = pow(b, 2) - 4 * a * c;
		double t1 = (-b - sqrt(delta)) / (2 * a);
		double t2 = (-b + sqrt(delta)) / (2 * a);
		if (t1 > 0 && t2 > 0) {
			cout << "x1 = " << sqrt(t1) << endl;
			cout << "x2 = " << -sqrt(t1) << endl;
			cout << "x3 = " << sqrt(t2) << endl;
			cout << "x4 = " << -sqrt(t2) << endl;
		}
		else if (t1 == 0 && t2 > 0) {
			cout << "x1 = " << sqrt(t1) << endl;
			cout << "x2 = " << sqrt(t2) << endl;
			cout << "x3 = " << -sqrt(t2) << endl;
		}
		else if (t1 > 0 && t2 == 0) {
			cout << "x1 = " << sqrt(t1) << endl;
			cout << "x2 = " << -sqrt(t1) << endl;
			cout << "x3 = " << sqrt(t2) << endl;
		}
		else if (t1 > 0 && t2 < 0) {
			cout << "x1 = " << sqrt(t1) << endl;
			cout << "x2 = " << -sqrt(t1) << endl;
		}
		else if (t1 < 0 && t2 > 0) {
			cout << "x1 = " << sqrt(t2) << endl;
			cout << "x2 = " << -sqrt(t2) << endl;
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