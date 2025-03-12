#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b;
    cout << "Vui long nhap lan luot phan tram hoan tien, hoan tien toi da thuc duong: ";
    cin >> a >> b;

    if (a > 0 && b > 0) {
        cout << fixed << setprecision(2);
        a /= 100;
        cout << "So tien phai chi de hoan tien toi da la: " << b / a << endl;
    }
    else {
        cout << "Vui long nhap phan tram hoan tien, hoan tien toi da thuc duong." << endl;
    }

    system("pause");
    return 0;
}
