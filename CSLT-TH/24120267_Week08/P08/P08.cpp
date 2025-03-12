#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int i, n;
    const char* original = "Alice";
    char x[100];
    strcpy_s(x, sizeof(x), original);
    n = strlen(x);
    x[n] = '\0';
    x[0] = x[n - 1];

    for (i = 0; i < n; i++) {
        cout << x << " ";
        memmove(x, x + 1, n - i);
    }

    cout << endl;
    return 0;
}