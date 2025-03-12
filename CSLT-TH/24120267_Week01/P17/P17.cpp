#include <iostream>

using namespace std;

int main() {
    int tien;
    cout << "Nhap so tien cua ban: ";
    cin >> tien;

    if (tien < 0) {
        cout << "So tien khong hop le" << endl;
    }

    int tienbandau = tien;

    int money500 = tien / 500000;
    tien %= 500000;

    int money200 = tien / 200000;
    tien %= 200000;

    int money100 = tien / 100000;
    tien %= 100000;

    int money50 = tien / 50000;
    tien %= 50000;

    int money20 = tien / 20000;
    tien %= 20000;

    int money10 = tien / 10000;
    tien %= 10000;

    int money5 = tien / 5000;
    tien %= 5000;

    int money2 = tien / 2000;
    tien %= 2000;

    int money1 = tien / 1000;
    tien %= 1000;

    cout << tienbandau << " = 500000: " << money500 << endl << "200000: " << money200 << endl << "100000: " << money100 << endl << " 50000: " << money50
        << endl << " 20000: " << money20 << endl << " 10000: " << money10 << endl << "  5000: " << money5 << endl << "  2000: " << money2 << endl << "  1000: " << money1 << endl;

    system("pause");
    return 0;
}