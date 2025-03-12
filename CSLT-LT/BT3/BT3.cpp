#include <iostream>
#define _Extream -1
using namespace std;

int const L1 = 4000000, L2 = 6000000, L3 = 9000000, L4 = 14000000, L5 = 24000000, L6 = 44000000, L7 = 84000000;
double const P1 = 0.0, P2 = 0.05, P3 = 0.10, P4 = 0.15, P5 = 0.20, P6 = 0.25, P7 = 0.30, P8 = 0.35;
double const deductionPerMem = 100000.0;
//Function declaration
double Tinh(int, int, double, size_t);
size_t TinhThue(size_t, size_t);
//Function definition
double Tinh(int L, int R, double P, size_t k) {
    double kq = 0;
    if (k < L) return kq;
    else {
        if (k < R || R == _Extream)
            kq = (k - L) * P;
        else
            kq = (R - L) * P;
    }
    return kq;
}
size_t TinhThue(size_t thuNhap, size_t soLuongGiamTru) {
    thuNhap -= soLuongGiamTru * (deductionPerMem * 12);
    size_t s = Tinh(0, L1, P1, thuNhap) +
        Tinh(L1, L2, P2, thuNhap) +
        Tinh(L2, L3, P3, thuNhap) +
        Tinh(L3, L4, P4, thuNhap) +
        Tinh(L4, L5, P5, thuNhap) +
        Tinh(L5, L6, P6, thuNhap) +
        Tinh(L6, L7, P7, thuNhap) +
        Tinh(L7, _Extream, P8, thuNhap);
    return s;
}
//main
int main() {
    size_t thuNhap;
    size_t soLuongGiamTru;
    cout << "Please enter your income: ";
    cin >> thuNhap;
    cout << "Please enter the number of your family members: ";
    cin >> soLuongGiamTru;
    size_t thue = TinhThue(thuNhap, soLuongGiamTru);
    cout << "The amount of tax you have to pay: " << thue << endl;
    system("pause");
    return 0;
}
