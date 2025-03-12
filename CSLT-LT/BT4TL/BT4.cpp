#include <iostream>

using namespace std;

#define N 20

int nhapSonguyen(int soNguyen[], int k) {
    for (int i = 0; i < k; i++) {
        cin >> soNguyen[i];
    }
    return 0;
}

int xuatSonguyen(int soNguyen[], int k) {
    cout << "Mang vua nhap la: ";
    for (int i = 0; i < k; i++) {
        cout << soNguyen[i] << " ";
    }
    cout << endl;
    return 0;
}

int tongSochan(int soNguyen[], int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        if (soNguyen[i] % 2 == 0) {
            sum += soNguyen[i];
        }
    }
    cout << "Tong cac so chan trong mang la: " << sum << endl;
    return 0;
}

int tichSole(int soNguyen[], int k) {
    int product = 1;
    for (int i = 0; i < k; i++) {
        if (soNguyen[i] % 2 != 0) {
            product *= soNguyen[i];
        }
    }
    cout << "Tich cac so le trong mang la: " << product << endl;
    return 0;
}

int demSo(int soNguyen[], int k) {
    int count = 0;
    bool isDistinct = true;
    for (int i = 0; i < k; i++) {
        isDistinct = true;
        for (int j = i + 1; j < k; j++) {
            if (soNguyen[i] == soNguyen[j]) {
                isDistinct = false;
                break;
            }
        }   
        if (isDistinct) {
            count++;
        }
    }
    cout << "So phan tu khac nhau trong mang la: " << count << endl;
    return 0;
}

void xoaySangtrai(int soNguyen2chieu[][N], int n) {
    int soBandau = soNguyen2chieu[0][0];
    for (int i = 0; i < n; ++i) {
        soNguyen2chieu[0][i] = soNguyen2chieu[0][i + 1];
    }
    for (int i = 0; i < n; ++i) {
        soNguyen2chieu[i][n - 1] = soNguyen2chieu[i + 1][n - 1];
    }
    for (int i = n - 1; i > 0; --i) {
        soNguyen2chieu[n - 1][i] = soNguyen2chieu[n - 1][i - 1];
    }
    for (int i = n - 1; i > 0; --i) {
        if (i != 0) {
            soNguyen2chieu[i][0] = soNguyen2chieu[i - 1][0];
        }
    }
    soNguyen2chieu[1][0] = soBandau;
}

void xuatMaTran(int soNguyen2chieu[][N], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << soNguyen2chieu[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int k;
    int soNguyen[N];
    cout << "Nhap kich thuong mang: ";
    cin >> k;

    if (0 <= k && k <= 20) {
        nhapSonguyen(soNguyen, k);
        xuatSonguyen(soNguyen, k);
        tongSochan(soNguyen, k);
        tichSole(soNguyen, k);
        demSo(soNguyen, k);
    }
    else {
        cout << "Vui long nhap kich thuoc <= 20" << endl;
    }

    int n;
    int soNguyen2chieu[N][N];
    cout << "Nhap kich thuoc mang 2 chieu: ";
    cin >> n;

    if (0 <= n && n <= 20) {
        cout << "Nhap cac phan tu cua mang 2 chieu:";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> soNguyen2chieu[i][j];
            }
        }

        cout << "Ma tran ban dau:" << endl;
        xuatMaTran(soNguyen2chieu, n);

        xoaySangtrai(soNguyen2chieu, n);

        cout << "\nMa tran sau khi xoay sang trai 1 don vi:" << endl;
        xuatMaTran(soNguyen2chieu, n);
    }
    else {
        cout << "Vui long nhap kich thuoc <= 20" << endl;
    }

    system("pause");
    return 0;
}