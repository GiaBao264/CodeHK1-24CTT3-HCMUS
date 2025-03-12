#include <iostream>
using namespace std;

int main() {
	int* x = new int;
	*x = 100;
	cout << "Value of *x: " << *x << endl;
	delete x;
	x = nullptr;

	system("pause");
	return 0;
}
