#include <iostream>

using namespace std;

int main() {
    int quantity;
    double price;

    cout << "Hay nhap so luong don hang: ";
    cin >> quantity;
    cout << "Hay nhap gia cua don hang: ";
    cin >> price;

    double total = quantity * price * 1.1;

    cout << endl << "Tien can phai tra la: " << (int)total << endl;

	system("pause");
	return 0;
}