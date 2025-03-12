#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Diem2D {
	float iX;
	float iY;
};

void nhapDiem(Diem2D &diem);
void xuatDiem(Diem2D diem);
float tinhKC(Diem2D& a, Diem2D& b);
int kTraGocPhan4(Diem2D diem);
void tinhSvaP(Diem2D a, Diem2D b, Diem2D c);
int kTraD(Diem2D a, Diem2D b, Diem2D c, Diem2D d);
