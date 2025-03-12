#include "Header.h"

Diem2D diem;
Diem2D a;
Diem2D b;
Diem2D c;
Diem2D d;

int main() {
	while (true) {
		system("cls");
		cout << fixed << setprecision(3);
		int choice = -1;
		string option[20] = {
			"[0] Thoat chuong trinh",
			"[1] Nhap va xuat Diem2D",
			"[2] K/cach giua 2 diem A, B",
			"[3] K/tra diem nam trong goc phan tu nao",
			"[4] Tinh chu vi va dien tich tam giac ABC",
			"[5] Kiem tra diem D co nam trong tam giac ABC khong",
			"Vui long nhap lua chon: "
		};
		for (int i = 1; i <= 5; ++i) {
			cout << option[i] << endl;
		}
		cout << option[6];
		cin >> choice;
		switch (choice) {
		case 0:
			return 0;
		case 1:
			nhapDiem(diem);
			xuatDiem(diem);
			break;
		case 2:
			cout << "Vui long nhap toa do 2 diem A, B: ";
			cout << "Diem A: ";
			nhapDiem(a);
			cout << "Diem B: ";
			nhapDiem(b);
			cout << tinhKC(a, b) << endl;
			break;
		case 3:
			cout << "Diem " << "(" << diem.iX << ", " << diem.iY << ")" << " nam o goc phan 4 thu " << kTraGocPhan4(diem) << endl;
			break;
		case 4:
			cout << "Vui long nhap toa do 3 diem A, B, C: ";
			cout << "Diem A: ";
			nhapDiem(a);
			cout << "Diem B: ";
			nhapDiem(b);
			cout << "Diem C: ";
			nhapDiem(c);
			tinhSvaP(a, b, c);
			cout << endl;
			break;
		case 5:
			cout << "Vui long nhap toa do 4 diem A, B, C, D: ";
			cout << "Diem A: ";
			nhapDiem(a);
			cout << "Diem B: ";
			nhapDiem(b);
			cout << "Diem C: ";
			nhapDiem(c);
			cout << "Diem D: ";
			nhapDiem(d);
			if (kTraD(a, b, c, d) == 1) {
				cout << "Diem D nam trong tam giac ABC" << endl;
			}
			else {
				cout << "Diem D nam ngoai tam giac ABC" << endl;
			}
			break;
		default:
			cout << "Khong hop le!";
			break;
		}
		cout << endl << option[0] << endl << option[6];
		cin >> choice;
		if (choice == 0) break;
	}

	system("pause");
	return 0 ^ 0;
}