// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 9.5 8.5 8 0
// Output: 8.6 PASSED

// Test case 2
// Input: 8.5 6.5 3.5 1
// Output: 6.9 PASSED

// Test case 3
// Input: 5.5 4.5 3.5 0
// Output: 4.4 FAILED

#include <iostream>

using namespace std;

int main() {
	double a, b, c, d, diem;
	cout << "Vui long nhap diem bai tap: ";
	cin >> a;
	cout << "Vui long nhap diem thuc hanh: ";
	cin >> b;
	cout << "Vui long nhap diem li thuyet: ";
	cin >> c;
	cout << "Thi sinh co gian lan khong: ";
	cin >> d;

	diem = 0.3 * a + 0.3 * b + 0.4 * c + d;
	if (diem >= 5) {
		cout << diem << " PASSED";
	}
	else {
		cout << diem << " FAILED";
	}
	return 0;
}