#include <iostream>
#include <cstring>

using namespace std;

bool isPalindrome(char* cstr) {
	char* front = cstr;
	char* back = cstr + strlen(cstr) - 1;
	while (front < back) {
		if (front != back) {
			return false;
		}
		front++;
		back--;
	}
	return true;
}

int main() {
	int n;
	cout << "Please enter string lens: ";
	cin >> n;

	char* cstr = new char[n + 1];

	cout << "Please enter the string: ";
	cin.ignore();
	cin.getline(cstr, n + 1);

	if (isPalindrome(cstr)) {
		cout << "The string is a palindrome." << endl;
	}
	else {
		cout << "The string is not a palindrome." << endl;
	}

	delete[] cstr;

	return 0;
}