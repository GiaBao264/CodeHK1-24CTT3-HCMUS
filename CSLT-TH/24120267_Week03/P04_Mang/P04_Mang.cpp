// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

#include <iostream>
#define N 100

using namespace std;

void nhapMang(double a[], int n) {
	cout << "Nhap cac phan tu mang: ";
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
}

int main() {
	int k;
	cout << "Nhap kich thuoc: ";
	cin >> k;

	double a[N];
	nhapMang(a, k);

	int max = 0;
	for (int i = 0; i < k; ++i) {
		if (round(a[i]) == a[i] && a[i] >= max) {
			max = a[i];
		}
	}
	cout << max;

	return 0;
}