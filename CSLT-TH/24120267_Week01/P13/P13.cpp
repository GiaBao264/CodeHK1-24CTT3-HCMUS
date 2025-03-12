#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    cout << "Vui long nhap do dai 3 canh tam giac (3 4 5): ";
    cin >> a >> b >> c;

    if (a > 0 && b > 0 && c > 0) {
        cout << fixed << setprecision(2);
        double nuaChuvi = (a + b + c) / 2;
        double dienTich = sqrt(nuaChuvi * (nuaChuvi - a) * (nuaChuvi - b) * (nuaChuvi - c));
        cout << "Chu vi va Dien tich tam giac lan luot la: " << nuaChuvi * 2 << " " << dienTich << endl;
    }
    else {
        cout << "Vui long nhap 3 canh > 0." << endl;
    }
    
    system("pause");
    return 0;
}
