// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

#include <iostream>
#define N 100

using namespace std;

void hoanVi(int a, int b) {
	a = a + b;
	b = a - b;
	a = a - b;
	cout << a << " " << b;
}

int main() {
	int a, b;
	cout << "Nhap 2 so a, b: ";
	cin >> a >> b;

	hoanVi(a, b);

	return 0;
}