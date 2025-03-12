// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

#include <iostream>
#define N 100

using namespace std;

int uocChung(int a, int b) {
	int c = 0;
	for (int i = 1; i <= a && i <= b; ++i) {
		if (a % i == 0 && b % i == 0) {
			c = i;
		}
	}
	return c;
}

int main() {
	int a, b;
	cout << "Nhap 2 so a, b: ";
	cin >> a >> b;

	cout << (a * b) / uocChung(a, b); //thuật toán euclid

	return 0;
}