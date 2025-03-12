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

int lonThuHai(int a[], int k) {
    int max = 0;
    int max2 = 0;
    for (int i = 0; i < k; ++i) {
        if (a[i] >= max) {
            max = a[i];
        }
    }
    for (int i = 0; i < k; ++i) {
        if (a[i] >= max2 && a[i] != max) {
            max2 = a[i];
        }
    }
    return max2;
}

int main() {
    int k;
    cout << "Nhap kich thuoc mang: ";
    cin >> k;

    int a[N];
    nhapMang(a, k);

    cout << lonThuHai(a, k);

    return 0;
}
