// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

#include <iostream>
#include <cmath>
#define N 100

using namespace std;

void nhapMang(int a[][], int n) {
    cout << "Nhap cac phan tu mang: ";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
}

int main() {
    int k;
    cout << "Nhap kich thuoc mang: ";
    cin >> k;

    int a[N][N];
    nhapMang(a, k);

    int tong = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tong += a[i][j];
        }
    }

    cout << tong;
    
    return 0;
}
