// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 2 7 5
// Output: 2 5 7

// Test case 2
// Input: 9 4 6
// Output: 4 6 9

// Test case 3
// Input: 4 2 6
// Output: 2 4 6

#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cout << "Vui long nhap 3 so nguyen khac nhau: ";
	cin >> a >> b >> c;
	
	if (a > b) {
		if (a > c && b > c) {
			cout << c << " " << b << " " << a;
		}
		else if (a > c && b < c) {
			cout << b << " " << c << " " << a;
		}
		else {
			cout << b << " " << a << " " << c;
		}
	}
	else if (a < b) {
		if (c > a && c < b) {
			cout << a << " " << c << " " << b;
		}
		else if (c > a && c > b) {
			cout << a << " " << b << " " << c;
		}
		else {
			cout << c << " " << a << " " << b;
		}
	}

	return 0;
}