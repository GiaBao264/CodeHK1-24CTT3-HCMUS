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

	for (int i = 1; i < k; ++i) {
		if (a[i - 1] % 2 == 0 && a[i - 1] >= a[i]) {
			swap(a[i - 1], a[i]);
		}
	}

	for (int j = 0; j < k; ++j) {
		cout << a[j];
	}

	return 0;
}