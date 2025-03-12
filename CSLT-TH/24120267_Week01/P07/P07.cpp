#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
	double n;
	cout << "Hay nhap vao so do goc (do): ";
	cin >> n;
	n = (n / 180) * M_PI;
	cout << "cos(n) = " << setprecision(2) << cos(n) << endl;

	system("pause");
	return 0;
}