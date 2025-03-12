#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b;
    cout << "Nhap chu vi cua hcn thuc duong: ";
    cin >> a;
    b = (a / 2) / 2.5;
    if (a > 0) {
        cout << fixed << setprecision(2);
        cout << "Dien tich hinh chu nhat la: " << b * b * 1.5 << endl;
    }
    else {
        cout << "Vui long nhap chu vi thuc duong" << endl;
    }

    system("pause");
    return 0;
}