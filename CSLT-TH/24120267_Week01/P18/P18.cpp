#include <iostream>

using namespace std;

int main() {
    int a, b;
    cout << "Nhap 2 so a, b nguyen duong: ";
    cin >> a >> b;
    if (a > 0 && b > 0) {
        swap(a, b);

        cout << "Sau khi doi vi tri: a = " << a << " b = " << b << endl;
    }
    else{
        cout << "Vui long nhap a va b nguyen duong" << endl;
    }

    system("pause");
    return 0;
}