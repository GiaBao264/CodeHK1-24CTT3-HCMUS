#include "header.h"

int main() {
	FILE* input;
	FILE* output;

	if (freopen_s(&input, "input.txt", "r", stdin) != 0) {
		cerr << "Khong the mo file." << endl;
		return 1;
	}
	if (freopen_s(&output, "output.txt", "w", stdout) != 0) {
		cerr << "Khong the xuat file." << endl;
		return 1;
	}

	Date a, b;
	string m, n, p;
	int c;

	cout << "Nhap 1 ngay, thang, nam la: " << endl;
	nhapNgay(a);
	xuatNgay(a);
	cout << endl;

	cout << "Nhap 2 ngay, thang, nam la: " << endl;
	nhapNgay(b);
	xuatNgay(a); xuatNgay(b);
	cout << endl;

	cin >> m >> n >> p;
	dinhDang(a, m, n, p);
	cout << endl;

	soSanhNgay(a, b);
	cout << endl;

	cout << "Ngay mai la ngay: ";
	xuatNgay(ngayMai(a));
	cout << endl;

	cout << "Ngay hom qua la ngay: ";
	xuatNgay(ngayHQua(a));
	cout << endl;

	nhapK(c);
	cout << "Tang them so ngay k la: ";
	xuatNgay(tangKNgay(c, a));
	cout << endl;

	cout << "Giam di so ngay k la: ";
	xuatNgay(giamKNgay(c, a));
	cout << endl;

	cout << "Khoang cach tu 01/01/" << a.year << " den " << a.day << "/" << a.month << "/" << a.year << " la: " << kCach1(a) << endl;
	cout << endl;

	cout << "Khoang cach tu 01/01/1970 den " << a.day << "/" << a.month << "/" << a.year << " la: " << kCach2(a) << endl;
	cout << endl;

	cout << "Khoang cach giua " << a.day << "/" << a.month << "/" << a.year << " va " << b.day << "/" << b.month << "/" << b.year << " la: " << kCach3(a, b) << endl;
	cout << endl;

	cout << "Ngay " << a.day << "/" << a.month << "/" << a.year << " la thu: " << thuMay(a) << endl;
	cout << endl;

	fclose(input);
	fclose(output);

	return 0 ^ 0;
}