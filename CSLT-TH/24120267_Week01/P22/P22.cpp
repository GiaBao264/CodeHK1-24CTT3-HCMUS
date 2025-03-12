#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double r, h;
    cout << "Vui long nhap lan luot ban kinh, chieu cao hinh tru thuc duong: ";
    cin >> r >> h;

    if (r > 0 && h > 0) {
        cout << fixed << setprecision(2);
        cout << "The tich hinh tru la: " << M_PI * pow(r, 2) * h << endl;
    }
    else {
        cout << "Vui long nhap ban kinh, chieu cao thuc duong." << endl;
    }

    system("pause");
    return 0;
}
