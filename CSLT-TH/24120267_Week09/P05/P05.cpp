#include <iostream>

using namespace std;

double findMedian(int* arr, int n) {
	if (n % 2 == 1) {
		return arr[n/2];
	}
	else {
		int mid1 = arr[n / 2 - 1];
		int mid2 = arr[n / 2];
		return (mid1 + mid2) / 2.0;
	}
}

int main() {
	int n;
	cout << "Please enter n of array: ";
	cin >> n;

	int* arr = new int[n];

	cout << "Please enter the elements: " << endl;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	double median = findMedian(arr, n);

	cout << "Median is: " << median;

	delete[] arr;

	return 0;
}