// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 2 10 2019
// Output: 1 10 2019

// Test case 2
// Input: 1 11 2019
// Output: 31 10 2019

// Test case 3
// Input: 1 1 2020
// Output: 31 12 2019

#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cout << "Vui long nhap ngay, thang, nam: ";
	cin >> a >> b >> c;

	if (b >= 1 && b <= 12 && c > 0 && 1 <= a && a <= 31) {
		if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && (a != 1)) {
			a--;
			cout << a << " " << b << " " << c;
		}
		else if ((b == 3 || b == 5 || b == 7 || b == 8 || b == 10) && (a == 1)) {
			a = 31;
			b--;
			cout << a << " " << b << " " << c;
		}
		else if (b == 1 && a == 1) {
			a = 31;
			b = 12;
			c--;
			cout << a << " " << b << " " << c;
		}
		else if ((b == 2 || b == 4 || b == 6 || b == 9 || b == 11) && (a != 1)) {
			a--;
			cout << a << " " << b << " " << c;
		}
		else if ((b == 4 || b == 6 || b == 9 || b == 11) && (a == 1)) {
			a = 31;
			b--;
			cout << a << " " << b << " " << c;
		}
		else if ((a == 1) && (b == 3) && (c % 4 == 0 && c % 100 != 0 || c % 400 == 0)) {
			a = 29;
			b--;
			cout << a << " " << b << " " << c;
		}
		else if (b == 1 && a == 1) {
			a = 31;
			b = 12;
			c--;
			cout << a << " " << b << " " << c;
		}
	}

	return 0;
}