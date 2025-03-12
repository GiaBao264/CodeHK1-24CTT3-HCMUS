// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

#include <iostream>
#define N 100

using namespace std;

int tinhF(int a) {
	if (a == 0) return 1;
	if (a == 1) return 2;
	return 3 * tinhF(a - 1) - 2 * tinhF(a - 2);
}

int main() {
	int a;
	cout << "Nhap so: ";
	cin >> a;

	cout << tinhF(a);

	return 0;
}