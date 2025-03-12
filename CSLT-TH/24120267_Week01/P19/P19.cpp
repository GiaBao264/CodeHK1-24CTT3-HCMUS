#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cout << "Nhap 3 so a, b, c nguyen duong: ";
    cin >> a >> b >> c;
    if (a > 0 && b > 0 && c > 0) {
        swap(a, b);
        swap(b, c);

        cout << "Sau khi doi vi tri: a = " << a << " b = " << b << " c = " << c << endl;
    }
    else {
        cout << "Vui long nhap a, b va c nguyen duong" << endl;
    }

    system("pause");
    return 0;
}