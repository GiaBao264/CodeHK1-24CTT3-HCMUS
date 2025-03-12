#include <iostream>  
using namespace std;

int main() {
    int* p, * q, v, nom[5];
    p = &v;
    *p = 12;
    q = p;
    nom[0] = *q;
    p = nom;
    p++;
    nom[2] = 12;
    *p = 13;
    *q = 10;
    v = 11;
    *(p + 3) = 16;
    p = &nom[3];
    *p = 10;
    p--;

    cout << *p << endl << *q << endl << v << endl << nom << endl;

    system("pause");
    return 0;
}
