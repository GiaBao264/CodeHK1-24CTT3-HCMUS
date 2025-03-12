// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

#include <iostream>
#define N 100

using namespace std;

int ktSoDX(int k) {
	int n = 0;
	while (k > 0) {
		n *= 10;
		n = n + k % 10;
		k /= 10;
	}
	return n;
}

int main() {
	int k;
	cout << "Nhap so nguyen: ";
	cin >> k;

	cout << k << " " << ktSoDX(k);

	return 0;
}