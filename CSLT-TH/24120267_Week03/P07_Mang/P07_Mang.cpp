// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

#include <iostream>
#include <cmath>
#define N 100

using namespace std;

void nhapMang(int a[], int n) {
    cout << "Nhap cac phan tu mang: ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

void xoaPhanTu(int a[], int k, int m, int n) {
    if (m >= 0 && n > 0 && m < k) {
        for (int j = m; j < k - n; ++j) {
            a[j] = a[j + n];
        }
    }
}

int main() {
    int k, m, n;
    cout << "Nhap kich thuoc, xoa tu ki tu thu, bao nhieu ki tu: ";
    cin >> k >> m >> n;

    int a[N];
    nhapMang(a, k);

    xoaPhanTu(a, k, m, n);
    k -= n;

    for (int j = 0; j < k; ++j) {
        cout << a[j] << " ";
    }

    return 0;
}
