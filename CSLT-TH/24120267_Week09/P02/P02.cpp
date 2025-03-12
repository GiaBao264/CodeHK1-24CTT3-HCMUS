#include <iostream>

using namespace std;

int doSomething(int* x, int* y) {
	int temp = *x;
	*x = *y * 10;
	*y = temp * 10;
	return *x + *y;
}

int main() {
	int x, y;

	cout << "Please enter x, y: ";
	cin >> x >> y;

	int result = doSomething(&x, &y);

	cout << "After doSomething x: " << x << " y: " << y << endl;
	cout << "Result: " << result;

	return 0;
}