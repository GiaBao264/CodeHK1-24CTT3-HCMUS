#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double m, h, p, s, timeTotal;
    cout << "Vui long nhap lan luot khoang cach, gio, phut, giay thuc duong: ";
    cin >> m >> h >> p >> s;

    if (m > 0 && h > 0 && p > 0 && s > 0) {
        cout << fixed << setprecision(2);
        timeTotal = h * 3600 + p * 60 + s;
        cout << "So phut/km va toc do lan luot la: " << (timeTotal / 60) / m << " " << m / (timeTotal / 3600) << endl;
    }
    else {
        cout << "Vui long nhap khoang cach, gio, phut, giay thuc duong." << endl;
    }

    system("pause");
    return 0;
}
