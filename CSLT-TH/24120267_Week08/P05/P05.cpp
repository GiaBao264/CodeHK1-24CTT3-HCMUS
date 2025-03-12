#include <iostream>

using namespace std;

int main() {
    int v = 8, * r, * s;
    int* p;
    int q = 100;
    r = p = &q;
    *p = 20;
    p = new int;
    *r = 30;
    s = &v;
    *s = 50;

    cout << *p << endl << q << endl << *r << endl << v << endl << *s << endl;

    delete p;

    return 0;
}
