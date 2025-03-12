#include <iostream>

using namespace std;

int main() {
	int a = 3;
	int* b = &a;
	cout << b << endl << *b << endl << &b << endl << a << endl << &a << endl;

	system("pause");
	return 0;
}