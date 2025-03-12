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

bool laSNT(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

void inSoNguyenTo(int a[], int n) {
    cout << "Cac so nguyen to trong mang la: ";
    for (int i = 0; i < n; ++i) {
        if (laSNT(a[i])) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int k;
    cout << "Nhap kich thuoc: ";
    cin >> k;

    int a[N];
    nhapMang(a, k);

    inSoNguyenTo(a, k);

    return 0;
}
