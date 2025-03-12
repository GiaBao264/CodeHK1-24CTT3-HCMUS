#include <iostream>

using namespace std;

void change(int* b, int n) {
    for (int i = 0; i < n; i++) {
        *(b + i) = *(b + i) + 5;
    }
}

int main() {
    int a[] = { 2, 4, 6, 8, 10 };
    change(a, 5);

    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
