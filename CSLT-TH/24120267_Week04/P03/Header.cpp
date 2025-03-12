#include "Header.h"

hocsinh hocSinh[200];

void sapTenTangDan(hocsinh ds[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(ds[i].hoTen, ds[j].hoTen) > 0) {
                hocsinh temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

int demTenKN(hocsinh ds[], int n) {
    int dem = 0;
    for (int i = 0; i < n; ++i) {
        bool tenMoi = true;
        for (int j = 0; j < i; j++) {
            if (strcmp(ds[i].hoTen, ds[j].hoTen) == 0) {
                tenMoi = false;
                break;
            }
        }
        if (tenMoi) {
            dem++;
            cout << ds[i].hoTen << endl;
        }
    }
    return dem;
}

void sapXepTheoDiem(hocsinh ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diem < ds[j].diem) {
                hocsinh temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}