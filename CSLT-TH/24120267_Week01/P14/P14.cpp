#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double r;
    cout << "Vui long nhap ban kinh hinh tron (3.2): ";
    cin >> r;

    if (r > 0) {
        cout << fixed << setprecision(2);
        cout << "Chu vi va Dien tich tam giac lan luot la: " << 2 * r * M_PI << " " << pow(r, 2) * M_PI << endl;
    }
    else {
        cout << "Vui long nhap ban kinh > 0." << endl;
    }

    system("pause");
    return 0;
}
