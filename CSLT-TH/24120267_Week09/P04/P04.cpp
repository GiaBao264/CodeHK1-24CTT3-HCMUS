#include <iostream>

using namespace std;

int findMode(int* arr, int n) {
	int mode = -1;
	int eCount = 0;

    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > eCount) {
            eCount = count;
            mode = arr[i];
        }
    }

    if (eCount == 1) {
        return -1;
    }

    return mode;
}

int main() {
	int n;

	cout << "Please enter size: ";
	cin >> n;

	int* arr = new int[n];

	cout << "Please enter the elements: " << endl;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

    int mode = findMode(arr, n);

    if (mode != -1) {
        cout << "Mode is: " << mode << endl;
    }
    else {
        cout << "Array don't have mode." << endl;
    }

    delete[] arr;

    return 0;
}