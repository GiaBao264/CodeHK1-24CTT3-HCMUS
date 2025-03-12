#include <iostream>

using namespace std;

int main() {
    int a = 10, * pa, & ra = a;
    pa = &a;

    cout << "a=" << ra;
    return 0;
}
