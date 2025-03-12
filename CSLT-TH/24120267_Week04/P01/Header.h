#pragma once
#include <iostream>
#include <math.h>
#include <algorithm>



using namespace std;

struct PhanSo {
    int iTuSo;
    int iMauSo;
};

void nhapPhanSo(PhanSo& ps);
void xuatPhanSo(PhanSo& ps);
void rutgonPS(PhanSo& ps);
PhanSo tongPS(PhanSo a, PhanSo b);
PhanSo hieuPS(PhanSo a, PhanSo b);
PhanSo tichPS(PhanSo a, PhanSo b);
PhanSo thuongPS(PhanSo a, PhanSo b);
int soSanh(PhanSo a, PhanSo b);
void nhapDayPS(PhanSo ps[], int n);
void xuatDayPS(PhanSo ps[], int n);
void thaythePSkhongtoigian(PhanSo ps[], int n);
PhanSo tongDayPS(PhanSo ps[], int n);
void sapXepPS(PhanSo ps[], int n);
bool kTraPS(PhanSo ps[], int n, PhanSo a);