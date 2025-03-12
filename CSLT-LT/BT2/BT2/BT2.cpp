#include <iostream>
#include <cstdlib>

using namespace std;

void divisorOfn(int h) {
    for (int e = 1; e <= h; e++) {
        if (h % e == 0) {
            cout << e << " ";
        }
    }
}

bool isPrime(int x) {
    if (x < 2) {
        return false;
    }
    for (int j = 2; j * j <= x; j++) {
        if (x % j == 0) {
            return false;
        }
    }
    return true;
}

void primeOfn(int h) {
    for (int i = 2; i < h; i++) {
        if (isPrime(i) == true) {
            cout << i << " ";
        }
    }
}

void primeDivisorsOfn(int h) {
    for (int e = 1; e <= h; e++) {
        if (h % e == 0 && isPrime(e)) {
            cout << e << " ";
        }
    }
}

int reverseNumber(int x) {
    int reversed = 0;
    while (x > 0) {
        int remainder = x % 10;
        reversed = reversed * 10 + remainder;
        x /= 10;
    }
    return reversed;
}

void reversedNumbersn(int n) {
    for (int i = 1; i < n; i++) {
        cout << reverseNumber(i) << " ";
    }
    cout << endl;
}

long int functionOfcompute(int n, int k) {
    double t = 1.0;
    double r = 1.0;
    double f = 1.0;

    for (int m = 1; m <= n; m++) {
        t *= m;
    }
    for (int m = 1; m <= (n - k); m++) {
        r *= m;
    }
    for (int m = 1; m <= k; m++) {
        f *= m;
    }
    double g = t / (r * f);
    cout << g;
    return 0;
}

int main() {
    int n;
    int k;
    cout << "Please enter n (n > 1): ";
    cin >> n;
    cout << endl;

    if (n <= 1) {
        cout << "Please enter n > 1.";
        return 0;
    }

    cout << "Divisors of " << n << " are: ";
    divisorOfn(n);
    cout << endl;

    cout << "Prime Divisors of " << n << " are: ";
    primeDivisorsOfn(n);
    cout << endl;

    cout << "Prime of " << n << " are: ";
    primeOfn(n);
    cout << endl;

    cout << "Symmetrical of " << n << " are: ";
    reversedNumbersn(n);
    cout << endl;

    cout << "Please enter n: ";
    cin >> n;
    cout << "Please enter k: ";
    cin >> k;
    cout << endl;

    if (k > n) {
        cout << "Enter n > k please!";
        return 0;
    }

    cout << "Combinatorial calculation is ";
    functionOfcompute(n, k);
    cout << endl;

    system("pause");
    return 0;
}
