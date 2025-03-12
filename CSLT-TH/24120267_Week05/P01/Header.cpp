#include "header.h"

string month[15] = { "0", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
int days[15] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string daysOW[15] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday" };

void nhapNgay(Date& a) {
	cin >> a.day >> a.month >> a.year;
}

void nhapK(int& k) {
	cin >> k;
}

void xuatNgay(Date a) {
	cout << a.year << " " << a.month << " " << a.day << endl;
}

void xuLi(Date a, string m) {
	if (m == "yyyy") cout << a.year;
	else if (m == "yy") cout << a.year % 100;
	else if (m == "mm") cout << a.month;
	else if (m == "mmm") cout << month[a.month];
	else if (m == "dd") cout << a.day;
}

void dinhDang(Date a, string m, string n, string p) {
	cout << "Ngay da dinh dang: ";
	xuLi(a, m);
	cout << " ";
	xuLi(a, n);
	cout << " ";
	xuLi(a, p);
	cout << endl;
}

void soSanhNgay(Date a, Date b) {
	if (a.day > b.day) {
		cout << "Ngay thu 1 lon hon ngay thu 2" << endl;
	}
	else {
		cout << "Ngay thu 1 be hon ngay thu 2" << endl;
	}
}

bool namNhuan(Date a) {
	return ((a.year % 4 == 0 && a.year % 100 != 0) || a.year % 400 == 0);
}

void isNamNhuan(Date a) {
	if (namNhuan(a) && a.month ==2) {
		days[2] = 29;
	}
	else {
		days[2] = 28;
	}
}

Date ngayMai(Date a) {
	Date tomor = a;
	isNamNhuan(a);
	if (tomor.day >= 1 && tomor.day < days[tomor.month]) {
		tomor.day++;
	}
	else if (tomor.day == days[tomor.month] && tomor.month < 12 && tomor.month >= 1) {
		tomor.day = 1;
		tomor.month++;
	}
	else if (tomor.day == days[tomor.month] && tomor.month == 12) {
		tomor.day = 1;
		tomor.month = 1;
		tomor.year++;
	}
	days[2] = 28;
	return tomor;
}

Date ngayHQua(Date a) {
	Date yest = a;
	isNamNhuan(a);
	if (yest.day > 1 && yest.day <= days[yest.month]) {
		yest.day--;
	}
	else if (yest.day == 1 && yest.month > 1 && yest.month <= 12) {
		yest.month--;
		yest.day = days[yest.month];
	}
	else if (yest.day == 1 && yest.month == 1) {
		yest.day = 31;
		yest.month = 12;
		yest.year--;
	}
	days[2] = 28;
	return yest;
}

Date tangKNgay(int k, Date a) {
	Date nextk = a;
	isNamNhuan(a);
	nextk.day += k;
	while (nextk.day > days[nextk.month]) {
		nextk.day -= days[nextk.month];
		nextk.month++;
		while (nextk.month > 12) {
			nextk.month -= 12;
			nextk.year++;
		}
	}
	days[2] = 28;
	return nextk;
}

Date giamKNgay(int k, Date a) {
	Date prek = a;
	isNamNhuan(a);
	prek.day -= k;
	while (prek.day < 1) {
		prek.month--;
		prek.day += days[prek.month];
		while (prek.month < 1) {
			prek.month += 12;
			prek.year--;
		}
	}
	days[2] = 28;
	return prek;
}

int kCach1(Date a) {
	Date kC = a;
	int khoangCach = 0;
	isNamNhuan(a);
	for (int i = 1; i < kC.month; ++i) {
		khoangCach += days[i];
	}
	khoangCach += kC.day;
	return khoangCach;
}

int kCach2(Date a) {
	Date kC = a;
	int khoangCach = 0;
	for (int i = 1970; i < kC.year; ++i) {
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) khoangCach += 366;
		else khoangCach += 365;
	}
	for (int i = 1; i < kC.month; ++i) {
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) days[2] = 29;
		else days[2] = 28;
		khoangCach += days[i];
	}
	khoangCach += kC.day;
	return khoangCach;
}

int kCach3(Date a, Date b) {
	int khoangCach = 0;
	Date maxx = a;
	Date minn = b;
	if ((a.year < b.year) || (a.year == b.year && a.month < b.month) || (a.year == b.year && a.month == b.month && a.day < b.day)) {
		maxx = b;
		minn = a;
	}
	else if (a.year == b.year && a.month == b.month && a.day == b.day) {
		return 0;
	}
	if (maxx.year == minn.year) {
		isNamNhuan(maxx);
		if (maxx.month == minn.month) khoangCach = maxx.day - minn.day + 1;
		else {
			khoangCach += days[minn.month] - minn.day + 1;
			for (int i = minn.month++; i < maxx.month; ++i) {
				khoangCach += days[i];
			}
			khoangCach += maxx.day;
		}
	}
	else {
		isNamNhuan(minn);
		khoangCach += days[minn.month] - minn.day + 1;
		for (int i = minn.month++; i <= 12; ++i) {
			khoangCach += days[i];
		}
		for (int i = minn.year++; i < maxx.year; ++i) {
			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) khoangCach += 366;
			else khoangCach += 365;
		}
	}
	return khoangCach;
}

string thuMay(Date a) {
	int soNgay = 3 + kCach2(a);
	return daysOW[soNgay % 7 - 1];
}