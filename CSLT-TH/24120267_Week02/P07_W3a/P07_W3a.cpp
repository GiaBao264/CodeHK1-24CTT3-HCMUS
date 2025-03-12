// 24120267
// Trần Huỳnh Gia Bảo
// CTT3A

// Test case 1
// Input: a
// Output: A a

// Test case 2
// Input: b
// Output: B b

// Test case 3
// Input: c
// Output: C c

#include <iostream>

using namespace std;

int main() {
	char a;
	cout << "Vui long chu cai: ";
	cin >> a;

	cout << "UPPERCASE " << (char)toupper(a) << endl;
	cout << "lowercase " << (char)tolower(a);

	return 0;
}