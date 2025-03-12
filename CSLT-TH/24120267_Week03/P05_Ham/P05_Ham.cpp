// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

#include <iostream>
#define N 100

using namespace std;

int demSoAm(int k) {
	int count = 0;
	while (cin >> k) {
		if (k == 0) break;
		if (k < 0) count++;
	}
	return count;
}

int main() {
	double k;
	cout << "Nhap so thuc: ";
	cin >> k;

	cout << demSoAm(k);

	return 0;
}