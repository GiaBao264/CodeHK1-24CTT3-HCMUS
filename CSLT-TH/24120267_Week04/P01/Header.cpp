#include "Header.h"

void nhapPhanSo(PhanSo& ps) {
    cout << "Nhap Tu so: ";
    cin >> ps.iTuSo;
    do {
        cout << "Nhap Mau so: ";
        cin >> ps.iMauSo;
        if (ps.iMauSo == 0) {
            cout << "Vui long nhap mau khac 0!" << endl;
        }
    } while (ps.iMauSo == 0);
}

void xuatPhanSo(PhanSo& ps) {
    cout << ps.iTuSo << "/" << ps.iMauSo << " ";
}

int uocChungLN(int a, int b) {
    while (b != 0) {
        int banDau = b;
        b = a % b;
        a = banDau;
    }
    return a;
}

void rutgonPS(PhanSo& ps) {
    int ucln = uocChungLN(ps.iTuSo, ps.iMauSo);
    ps.iTuSo /= ucln;
    ps.iMauSo /= ucln;
}

PhanSo tongPS(PhanSo a, PhanSo b) {
    PhanSo tong;
    tong.iTuSo = a.iTuSo * b.iMauSo + b.iTuSo * a.iMauSo;
    tong.iMauSo = a.iMauSo * b.iMauSo;
    rutgonPS(tong);
    return tong;
}

PhanSo hieuPS(PhanSo a, PhanSo b) {
    PhanSo hieu;
    hieu.iTuSo = a.iTuSo * b.iMauSo - b.iTuSo * a.iMauSo;
    hieu.iMauSo = a.iMauSo * b.iMauSo;
    rutgonPS(hieu);
    return hieu;
}

PhanSo tichPS(PhanSo a, PhanSo b) {
    PhanSo tich;
    tich.iTuSo = a.iTuSo * b.iTuSo;
    tich.iMauSo = a.iMauSo * b.iMauSo;
    rutgonPS(tich);
    return tich;
}

PhanSo thuongPS(PhanSo a, PhanSo b) {
    if (b.iTuSo == 0) {
        cout << "Khong the chia cho 0!" << endl;
        return { 0, 1 };
    }
    PhanSo thuong;
    thuong.iTuSo = a.iTuSo * b.iMauSo;
    thuong.iMauSo = a.iMauSo * b.iTuSo;
    rutgonPS(thuong);
    return thuong;
}

int soSanh(PhanSo a, PhanSo b) {
    int ps1 = a.iTuSo * b.iMauSo;
    int ps2 = b.iTuSo * a.iMauSo;
    if (ps1 > ps2)return 1;
    if (ps1 < ps2)return -1;
    return 0;
}

void nhapDayPS(PhanSo ps[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Nhap PS thu " << i + 1 << ":\n";
        nhapPhanSo(ps[i]);
    }
}

void xuatDayPS(PhanSo ps[], int n) {
    for (int i = 0; i < n; ++i) {
        xuatPhanSo(ps[i]);
    }
}

void thaythePSkhongtoigian(PhanSo ps[], int n) {
    for (int i = 0; i < n; ++i) {
        rutgonPS(ps[i]);
    }
}

PhanSo tongDayPS(PhanSo ps[], int n) {
    PhanSo tong = { 0,1 };
    for (int i = 1; i < n; ++i) {
        tong = tongPS(tong, ps[i]);
    }
    return tong;
}

void hoanDoi(PhanSo& a, PhanSo& b) {
    PhanSo bD = a;
    a = b;
    b = bD;
}

void sapXepPS(PhanSo ps[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (soSanh(ps[i], ps[j]) > 0) {
                hoanDoi(ps[i], ps[j]);
            }
        }
    }
}

bool kTraPS(PhanSo ps[], int n, PhanSo a) {
    for (int i = 0; i < n; i++) {
        if (soSanh(ps[i], a) == 0)
            return true;
    }
    return false;
}