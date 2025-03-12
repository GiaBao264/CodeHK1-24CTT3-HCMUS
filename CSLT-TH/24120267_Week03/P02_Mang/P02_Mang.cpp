// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

#include <iostream>
#include <iomanip>
#define N 100

using namespace std;

void nhapMang(int a[], int n) {
	cout << "Nhap cac phan tu mang: ";
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
}

int main() {
	int k;
	cout << "Nhap kich thuoc: ";
	cin >> k;
	cout << fixed << setprecision(2);

	int a[N];
	nhapMang(a, k);

	double tong = 0.0;
	double count = 0.0;
	for (int i = 0; i < k; ++i) {
		if (a[i] % 2 == 0) {
			tong += a[i];
			count++;
		}
	}
	cout << tong / count;

	return 0;
}