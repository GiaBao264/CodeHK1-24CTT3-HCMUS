#include "Header.h"

hocsinh dsHS[200];

int main() {
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;

    if (n < 1 || n>200) {
        cout << "Vui long nhap 1 <= n <= 200!";
        return 0 ^ 0;
    }

    while (true) {
        system("cls");
        int choice = -1;
        string option[20] = {
            "[0] Thoat chuong trinh",
            "[1] Nhap va xuat du lieu hoc sinh",
            "[2] Sap xep ten theo thu tu tang dan",
            "[3] So luong ten khac nhau",
            "[4] Top 3 hoc sinh diem cao nhat",
            "Vui long nhap lua chon: "
        };
        for (int i = 1; i <= 4; ++i) {
            cout << option[i] << endl;
        }
        cout << option[5];
        cin >> choice;
        switch (choice) {
        case 0:
            return 0;
        case 1:
            for (int i = 0; i < n; i++) {
                cout << "Nhap diem cua hoc sinh thu: " << i + 1 << ": ";
                cin >> dsHS[i].diem;

                cin.ignore();
                cout << "Nhap ten hoc sinh thu: " << i + 1 << ": ";
                cin.getline(dsHS[i].hoTen, 31);
            }
        case 2:
            sapTenTangDan(dsHS, n);
            cout << "\nDanh sach da sap xep:\n";
            for (int i = 0; i < n; i++) {
                cout << dsHS[i].hoTen << endl;
            }
        case 3: {
            int soTenKN = demTenKN(dsHS, n);
            cout << "\nSo luong ten khac nhau trong danh sach: " << soTenKN << endl;
        }
        case 4:
            sapXepTheoDiem(dsHS, n);
            cout << "\nTop 3 hoc sinh co diem cao nhat la:\n";
            for (int i = 0; i < 3 && i < n; i++) {
                cout << "Thu " << i + 1 << dsHS[i].hoTen << " - " << dsHS[i].diem << endl;
            }
        default:
            cout << "Khong hop le!";
            break;
        }
        cout << endl << option[0] << endl << option[5];
        cin >> choice;
        if (choice == 0) break;
    }

    system("pause");
    return 0;
}