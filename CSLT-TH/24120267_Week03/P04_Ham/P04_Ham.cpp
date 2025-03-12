// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

#include <iostream>
#define N 100

using namespace std;

int soLN(int k) {
	int n = 0;
	int max = INT_MIN;
	while (k > 0) {
		n = k % 10;
		k /= 10;
		if (n > max) {
			max = n;
		}
	}
	return max;
}

int main() {
	int k;
	cout << "Nhap so nguyen: ";
	cin >> k;

	cout << soLN(k);

	return 0;
}