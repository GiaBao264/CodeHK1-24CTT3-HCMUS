#include <iostream>

using namespace std;

int main() {
    int a;
    int b;
    int c = 0;
    cout << "Vui long nhap bien so co 5 chu so nguyen duong (12345): ";
    cin >> a;

    if (a >= 10000 && a <= 99999) {
        while (a > 0) {
            b = a % 10;
            c += b;
            a = (a - b) / 10;
        }
        while (c >= 10) {
            c -= 10;
        }
        cout << "So nut cua bien so la: " << c << endl;
    }
    else {
        cout << "Vui long nhap bien so co 5 chu so nguyen duong." << endl;
    }

    system("pause");
    return 0;
}
