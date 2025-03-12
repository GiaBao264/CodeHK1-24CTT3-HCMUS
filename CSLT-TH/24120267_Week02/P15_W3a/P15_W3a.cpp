// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 1 10 2019
// Output: 2 10 2019

// Test case 2
// Input: 31 10 2019
// Output: 1 11 2019

// Test case 3
// Input: 31 12 2019
// Output: 1 1 2020

#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cout << "Vui long nhap ngay, thang, nam: ";
	cin >> a >> b >> c;

	if (b >= 1 && b <= 12 && c > 0 && 1 <= a && a <= 31) {
		if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && (a != 31)) {
			a++;
			cout << a << " " << b << " " << c;
		}
		else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10) && (a == 31)) {
			a = 1;
			b++;
			cout << a << " " << b << " " << c;
		}
		else if (b == 12 && a == 31) {
			a = 1;
			b = 1;
			c++;
			cout << a << " " << b << " " << c;
		}
		else if ((b == 4 || b == 6 || b == 9 || b == 11) && (a < 30)) {
			a++;
			cout << a << " " << b << " " << c;
		}
		else if ((b == 4 || b == 6 || b == 9 || b == 11) && (a == 30)) {
			a = 1;
			b++;
			cout << a << " " << b << " " << c;
		}
		else if (b == 2 && (c % 4 == 0 && c % 100 != 0 || c % 400 == 0)) {
			if (a <= 28) {
				a++;
				cout << a << " " << b << " " << c;
			}
			else if (a == 29) {
				a = 1;
				b++;
				cout << a << " " << b << " " << c;
			}
		}
		else if (b == 2) {
			if (a < 28) {
				a++;
				cout << a << " " << b << " " << c;
			}
			else if (a == 28) {
				a = 1;
				b++;
				cout << a << " " << b << " " << c;
			}
		}
	}

	return 0;
}