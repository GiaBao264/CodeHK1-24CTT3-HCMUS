// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

#include <iostream>
#define N 100

using namespace std;

bool ktSoHC(int k) {
	int tong = 0;
	int tich = 1;
	for (int i = 1; i < k; ++i) {
		if (k % i == 0) {
			tong += i;
			tich *= i;
		}
	}
	if (tong == tich) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int k;
	cout << "Nhap so nguyen: ";
	cin >> k;

	if (ktSoHC(k)) {
		cout << "la so hoan chinh";
	}
	else {
		cout << "khong la so hoan chinh";
	}

	return 0;
}