// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

#include <iostream>
#define N 100

using namespace std;

void nhiPhan(int a) {
	int nhiPhan[8] = { 0 };
	int triTuyetdoi;
	if (a >= 0) {
		triTuyetdoi = a;
	}
	else {
		triTuyetdoi = 255 + a;
	}
	for (int i = 7; i >= 0; --i) {
		nhiPhan[i] = triTuyetdoi % 2;
		triTuyetdoi /= 2;
	}
	for (int j = 0; j < 8; ++j) {
		cout << nhiPhan[j];
	}
}

int main() {
	int a;
	cout << "Nhap so: ";
	cin >> a;

	nhiPhan(a);

	return 0;
}