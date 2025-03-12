#include <iostream>

using namespace std;

int* narray(int* oarr, int n) {
	int* narr = new int[n * 2];
	for (int i = 0; i < n; ++i) {
		narr[i] = oarr[i];
	}
	for (int j = n; j < n * 2; ++j) {
		narr[j] = 0;
	}
	return narr;
}

int main() {
	int n;
	cout << "Please enter size of array: ";
	cin >> n;

	int* oarr = new int[n];

	cout << "Please enter the elements: " << endl;

	for (int i = 0; i < n; ++i) {
		cin >> oarr[i];
	}

	int* narr = narray(oarr, n);

	cout << "New array is: " << endl;
	for (int i = 0; i < n * 2; ++i) {
		cout << narr[i] << " ";
	}
	cout << endl;

	delete[] oarr;
	delete[] narr;

	return 0;
}