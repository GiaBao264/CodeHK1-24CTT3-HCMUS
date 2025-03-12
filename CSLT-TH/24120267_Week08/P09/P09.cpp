#include <iostream>

using namespace std;

int main() {
    char str[] = "peace";
    char* s = str;
    cout << (s++ + 3) << endl;
    return 0;
}
