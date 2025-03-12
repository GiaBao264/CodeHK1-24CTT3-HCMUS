// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

#include <iostream>
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

	int a[N];
	nhapMang(a, k);

	int min = INT_MAX;
	int max = INT_MIN;

	for (int i = 0; i < k; ++i) {
		if (a[i] % 2 == 0 && a[i] >= max) {
			max = a[i];
		}

		if (a[i] % 2 != 0 && a[i] <= min) {
			min = a[i];
		}
	}

	cout << max << " " << min;

	return 0;
}