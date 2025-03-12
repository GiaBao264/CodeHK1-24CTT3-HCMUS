// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: 3 4 5
// Output: Tam giac vuong tai C

// Test case 2
// Input: 5 5 5
// Output: Tam giac deu

// Test case 3
// Input: 10 10 21
// Output: Khong la tam giac

#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cout << "Vui long nhap 3 canh tam giac a, b, c: ";
	cin >> a >> b >> c;

	if (a + b > c && a + c > b && b + c > a) {
		if (a == b && a == c) {
			cout << "Tam giac deu";
		}
		else if (a == b) {
			cout << "Tam giac can tai C";
		}
		else if (a == c) {
			cout << "Tam giac can tai B";
		}
		else if (b == c) {
			cout << "Tam giac can tai A";
		}
		else if (a * a + b * b == c * c) {
			cout << "Tam giac vuong tai C";
		}
		else if (a * a + c * c == b * b) {
			cout << "Tam giac vuong tai B";
		}
		else if (c * c + b * b == a * a) {
			cout << "Tam giac vuong tai A";
		}
		else if ((a * a + b * b == c * c) && (a == b)) {
			cout << "Tam giac vuong can tai C";
		}
		else if ((a * a + c * c == b * b) && (a == c)) {
			cout << "Tam giac vuong can tai B";
		}
		else if ((c * c + b * b == a * a) && (b == c)) {
			cout << "Tam giac vuong can tai A";
		}
	}
	else {
		cout << "Khong la tam giac";
	}

	return 0;
}