// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 10 50 102
// Output: 4181760

// Test case 2
// Input: 5 40 90
// Output: 2354360

// Test case 3
// Input: 2 15 15
// Output: 355060

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a, b, c;
    cout << "Vui long nhap so nguoi, so nuoc thang truoc, so nuoc hien tai: ";
    cin >> a >> b >> c;

    if (1 <= a && a <= 10 && b >= 0 && c >= b) {
        int soNuoc = c - b;
        double tongTien = 0;

        if (soNuoc <= 4) {
            tongTien = soNuoc * 3300;
        }
        else if (soNuoc <= 6) {
            tongTien = 4 * 3300 + (soNuoc - 4) * 5200;
        }
        else {
            tongTien = 4 * 3300 + 2 * 5200 + (soNuoc - 6) * 7000;
        }

        tongTien = a * tongTien + tongTien + 1.1 * tongTien;

        cout << "Tien phai tra la: " << fixed << setprecision(0) << tongTien << endl;
    }
    else {
        cout << "Khong hop le" << endl;
    }

    return 0;
}
