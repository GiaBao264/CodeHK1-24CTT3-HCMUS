// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 3
// Output: 42000

// Test case 2
// Input: 15
// Output: 158850

// Test case 3
// Input: 6
// Output: 77500

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a;
    cout << "Vui long nhap so km: ";
    cin >> a;

    double tongTien;
    cout << fixed << setprecision(0);
    if (a == 1) {
        tongTien = 15000;
    }
    else if (2 <= a && a < 5) {
        tongTien = 15000 + (a - 1) * 13500;
    }
    else if (5 <= a && a < 12) {
        tongTien = 15000 + 3 * 13500 + (a - 4) * 11000;
    }
    else {
        tongTien = (15000 + 3 * 13500 + (a - 4) * 11000) - (15000 + 3 * 13500 + (a - 4) * 11000) * 0.1;
    }
    cout << tongTien;

    return 0;
}
