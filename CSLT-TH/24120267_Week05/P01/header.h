#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <math.h>

using namespace std;

struct Date {
	int day, month, year;
};

void nhapNgay(Date& a);
void nhapK(int& k);
void xuatNgay(Date a);
void dinhDang(Date a, string m, string n, string p);
void soSanhNgay(Date a, Date b);
void isNamNhuan(Date a);
Date ngayMai(Date a);
Date ngayHQua(Date a);
Date tangKNgay(int k, Date a);
Date giamKNgay(int k, Date a);
int kCach1(Date a);
int kCach2(Date a);
int kCach3(Date a, Date b);
string thuMay(Date a);

#endif