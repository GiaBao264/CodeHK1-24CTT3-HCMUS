#include <iostream>

using namespace std;

int main() {
	int* a = new int;
	int* b = new int;
	*a = 2;
	b = a;
	cout << *a << endl << *b << endl;
	delete a;

	system("pause");
	return 0;
}