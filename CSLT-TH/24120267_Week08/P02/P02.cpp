#include <iostream>

using namespace std;

int main() {
	int x, z;
	float y;
	char ch, * chp;
	int* ip1, * ip2;
	float* fp;

	x = 100;
	y = 20.0;
	z = 50;
	ch = 'Z';

	ip1 = &x;
	ip2 = &z;
	fp = &y;
	chp = &ch;
	ip2 = ip1;
	ip1 = &z;
	*ip1 = *ip2;
	*ip1 = 200;
	*ip1 = *ip2 + 300;
	*fp = 1.2;

	cout << x << endl << y << endl << z << endl << endl;
	cout << ip1 << endl << *ip1 << endl << &ip1 << endl << endl;
	cout << ip2 << endl << *ip2 << endl << &ip2 << endl << endl;
	cout << fp << endl << *fp << endl << &fp << endl << endl;
	cout << chp << endl << *chp << endl << &chp << endl;

	system("pause");
	return 0;
}