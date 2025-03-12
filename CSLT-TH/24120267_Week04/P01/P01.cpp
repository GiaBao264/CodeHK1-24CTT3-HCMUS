#include "Header.h"

const int N = 20;

int main() {
	while (true) {
		PhanSo ps[N];
		system("cls");
		int n = 0;
		int choice = -1;
		string option[20] = {
			"[0] Thoat chuong trinh",
			"[1] Nhap va xuat phan so",
			"[2] Rut gon phan so",
			"[3] Tinh tong, hieu, tich, thuong cua 2 phan so",
			"[4] So sanh 2 phan so",
			"[5] Nhap xuat day n phan so",
			"[6] Toi gian day phan so",
			"[7] Tong cac phan so trong day",
			"[8] Sap xep day phan so tang dan",
			"[9] Kiem tra su ton tai cua so k",
			"Vui long nhap lua chon: "
		};
		for (int i = 1; i <= 9; ++i) {
			cout << option[i] << endl;
		}
		cout << option[10];
		cin >> choice;
		switch (choice) {
		case 0:
			return 0;
		case 1:
			cout << "Nhap phan so thu nhat: ";
			nhapPhanSo(ps[0]);
			cout << endl;
			cout << "Nhap phan so thu hai: ";
			nhapPhanSo(ps[1]);
			cout << endl;
			cout << "Phan so thu nhat: ";
			xuatPhanSo(ps[0]);
			cout << endl;
			cout << "Phan so thu hai: ";
			xuatPhanSo(ps[1]);
			cout << endl;
			break;
		case 2:
			rutgonPS(ps[0]);
			break;
		case 3:
			PhanSo tong = tongPS(ps[0], ps[1]);
			PhanSo hieu = hieuPS(ps[0], ps[1]);
			PhanSo tich = tichPS(ps[0], ps[1]);
			PhanSo thuong = thuongPS(ps[0], ps[1]);
			cout << "Tong: ";
			xuatPhanSo(tong);
			cout << "Hieu: ";
			xuatPhanSo(hieu);
			cout << "Tich: ";
			xuatPhanSo(tich);
			cout << "Thuong: ";
			xuatPhanSo(thuong);
			break;
		case 4: {
			int kQ = soSanh(ps[0], ps[1]);
			if (kQ > 0) {
				cout << "Phan so thu nhat lon hon phan so thu hai." << endl;
			}
			else if (kQ < 0) {
				cout << "Phan so thu nhat nho hon phan so thu hai." << endl;
			}
			else {
				cout << "Hai phan so bang nhau." << endl;
			}
			break;
		}
		case 5:
			int n;
			cout << "Nhap so luong phan so: ";
			cin >> n;

			nhapDayPS(ps, n);

			cout << "Day PS ban dau la: ";
			xuatDayPS(ps, n);
			cout << endl;
			break;
		case 6:
			thaythePSkhongtoigian(ps, n);
			cout << "Day PS da toi gian la: ";
			xuatDayPS(ps, n);
			cout << endl;
			break;
		case 7:
			PhanSo tongDay = tongDayPS(ps, n);
			cout << "Tong cac day phan so la: ";
			xuatPhanSo(tongDay);
			cout << endl;
			break;
		case 8:
			sapXepPS(ps, n);
			cout << "Day phan so sau khi sap xep tang dan la: ";
			xuatDayPS(ps, n);
			cout << endl;
			break;
		case 9:
			PhanSo a;
			cout << "Nhap phan so can kiem tra: " << endl;
			nhapPhanSo(a);
			if (kTraPS(ps, n, a)) {
				cout << "Phan so co trong day." << endl;
			}
			else {
				cout << "Phan so khong co trong day." << endl;
			}
			break;
		default:
			cout << "Khong hop le!";
			break;
		}
		cout << endl << option[0] << endl << option[10];
		cin >> choice;
		if (choice == 0) break;
	}

	system("pause");
	return 0 ^ 0;
}