#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int a; int b;
	cout << "Hay nhap 2 so nguyen a va b (2 5): ";
	cin >> a >> b;
	cout << a << " / " << b << " = " << setprecision(2) << a / b << endl;
	system("pause");
	return 0;
}