#include <iostream>

using namespace std;

int main() {
	double a;
	double b;
	cout << "Hay nhap tien dien (thangtruoc thanghientai): ";
	cin >> a >> b;

	if (a <= 0 || b <= 0) {
		cout << "Vui long nhap gia tri a va b la so thuc duong." << endl;
	}
	else if (b > a) {
		cout << "Chi so dien tieu thu la: " << b - a << endl;
	}
	else {
		cout << "Vui long nhap thanghientai > thangtruoc." << endl;
	}

	system("pause");
	return 0;
}