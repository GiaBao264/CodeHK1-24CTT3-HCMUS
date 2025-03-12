#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cout << "Hay nhap vao so do goc (do khac 90 + k180): ";
	cin >> n;
	if (n % 180 != 90) {
		double k = ( (double)n / 180) * M_PI;
		cout << "tan(n) = " << setprecision(2) << tan(k) << endl;
	}
	else {
		cout << "Vui long nhap vao do khac 90 + k180. " << endl;
	}

	system("pause");
	return 0;
}