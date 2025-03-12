#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c;
    cout << "Vui long nhap lan luot chieu rong, chieu dai, chieu cao cua hinh hop chu nhat thuc duong: ";
    cin >> a >> b >> c;
    if (a > 0) {
        cout << fixed << setprecision(2);
        cout << "The tich hinh hop chu nhat la: " << a * b * c << endl;
    }
    else {
        cout << "Vui long nhap 3 canh thuc duong" << endl;
    }

    system("pause");
    return 0;
}