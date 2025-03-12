#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, r;
    cout << "Vui long nhap lan luot canh tam giac deu, ban kinh hinh tron thuc duong: ";
    cin >> a >> r;

    if (a > 0 && r > 0) {
        cout << fixed << setprecision(2);
        double dienTichhinhtron = M_PI * pow(r, 2);
        double dienTichhinhtamgiac = pow(a, 2) * (sqrt(3) / 4);
        cout << "Dien tich hinh la: " << dienTichhinhtamgiac * 3 + (dienTichhinhtron / 2) << endl;
    }
    else {
        cout << "Vui long nhap canh tam giac deu, ban kinh hinh tron thuc duong." << endl;
    }

    system("pause");
    return 0;
}
