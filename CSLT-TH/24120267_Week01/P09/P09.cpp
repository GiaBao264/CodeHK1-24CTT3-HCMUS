#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cout << "Hay nhap vao so do goc (do khac k180): ";
	cin >> n;
	if (n % 180 != 0) {
		double k = ((double)n / 180) * M_PI;
		cout << "cotan(n) = " << setprecision(2) << 1/tan(k) << endl;
	}
	else {
		cout << "Vui long nhap vao do khac k180. " << endl;
	}

	system("pause");
	return 0;
}