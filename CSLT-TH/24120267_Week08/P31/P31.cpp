#include <iostream>

using namespace std;

int main() {
    const int i = 20;
    const int* ptr = &i;
    int j = 15;
    ptr = &j;
    cout << *ptr;

    return 0;
}
