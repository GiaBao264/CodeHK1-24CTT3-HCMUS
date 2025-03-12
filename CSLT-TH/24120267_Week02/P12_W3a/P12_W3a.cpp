// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 2 7 5 12
// Output: 12 2

// Test case 2
// Input: 2 6 8 4
// Output: 8 2

// Test case 3
// Input: 1 5 9 8
// Output: 9 1

#include <iostream>

using namespace std;

int main() {
	int a, b, c, d;
	cout << "Vui long nhap 4 so nguyen khac nhau: ";
	cin >> a >> b >> c >> d;
	int MAX = a;
	int MIN = a;

	if (b >= MAX) {
		MAX = b;
	}
	if (c >= MAX) {
		MAX = c;
	}
	if (d >= MAX) {
		MAX = d;
	}

	if (b <= MIN) {
		MIN = b;
	}
	if (c <= MIN) {
		MIN = c;
	}
	if (d <= MIN) {
		MIN = d;
	}

	cout << "Gia tri lon nhat: " << MAX << endl;
	cout << "Gia tri nho nhat: " << MIN << endl;

	return 0;
}