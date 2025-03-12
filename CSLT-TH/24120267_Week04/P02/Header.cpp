#include "Header.h"

void nhapDiem(Diem2D &diem) {
	cout << "Nhap hoanh do: ";
	cin >> diem.iX;
	cout << "Nhap tung do: ";
	cin >> diem.iY;
}

void xuatDiem(Diem2D diem) {
	cout << "(" << diem.iX << ", " << diem.iY << ")" << endl;
}

float tinhKC(Diem2D &a, Diem2D &b) {
	float kCach = sqrt(pow(a.iX - b.iX, 2) + pow(a.iY - b.iY, 2));
	return kCach;
}

int kTraGocPhan4(Diem2D diem) {
	if (diem.iX > 0 && diem.iY > 0) {
		return 1;
	}
	else if (diem.iX < 0 && diem.iY > 0) {
		return 2;
	}
	else if (diem.iX < 0 && diem.iY < 0) {
		return 3;
	}
	else {
		return 4;
	}
}

void tinhSvaP(Diem2D a, Diem2D b, Diem2D c) {
	float ab = tinhKC(a, b);
	float bc = tinhKC(b, c);
	float ca = tinhKC(c, a);
	float S = ab + bc + ca;
	float p = S / 2;
	float P = sqrt(p * (p - ab) * (p - bc) * (p - ca));
	cout << "Chu vi tam giac la: " << S << endl;
	cout << "Dien tich tam giac la: " << P << endl;
}

int kTraD(Diem2D a, Diem2D b, Diem2D c, Diem2D d) {
	float ad = tinhKC(a, d);
	float bd = tinhKC(b, d);
	float cd = tinhKC(c, d);

	float ab = tinhKC(a, b);
	float bc = tinhKC(b, c);
	float ca = tinhKC(c, a);

	if (ad < ab && ad < ca && bd < ab && bd < bc && cd < bc && cd < ca) {
		return 1;
	}
	else {
		return 0;
	}
}