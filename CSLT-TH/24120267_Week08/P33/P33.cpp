#include <iostream>

using namespace std;

int main() {
	int arr[] = { 4, 5, 6, 7 };
	int* ptr = (arr + 1);
	cout << *arr + 10;
	return 0;
}