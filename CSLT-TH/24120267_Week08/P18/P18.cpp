#include <iostream>

using namespace std;

int main() {
	int a = 5, b = 10, c = 15;
	int* arr[] = { &a, &b, &c };
	cout << arr[1];
	return 0;
}