// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

#include <iostream>
#include <cmath>
#define N 100

using namespace std;

void nhapMang1(int a[], int n) {
    cout << "Nhap cac phan tu mang 1: ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

void nhapMang2(int b[], int n) {
    cout << "Nhap cac phan tu mang 2: ";
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
}

void trungLap(int a[], int b[], int k, int l) {
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < l; ++j) {
            if (a[i] == b[j]) {
                cout << a[i] << " ";
            }
        }
    }
}

int main() {
    int k, l;
    cout << "Nhap kich thuoc mang 1, 2: ";
    cin >> k >> l;
    
    int a[N];
    nhapMang1(a, k);
    int b[N];
    nhapMang2(b, l);

    trungLap(a, b, k, l);

    return 0;
}
