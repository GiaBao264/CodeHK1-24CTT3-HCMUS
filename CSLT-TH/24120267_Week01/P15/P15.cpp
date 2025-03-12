#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double x, y1, y2;
    cout << "Vui long nhap x (10): ";
    cin >> x;

    if (x > 0) {
        cout << fixed << setprecision(10);
        y1 = 4 * (pow(x, 2) + 10 * x * sqrt(x) + 3 * x + 1);
        y2 = (sin(M_PI * pow(x, 2)) + sqrt(pow(x, 2) + 1)) / (pow(M_E, x * 2) + cos((M_PI / 4) * x));
        cout << "Gia tri cua y1 va y2 lan luot la: " << y1 << " " << y2 << endl;
    }
    else {
        cout << "Vui long nhap so thuc > 0." << endl;
    }

    system("pause");
    return 0;
}
