#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> intStair;

void intStairInput(intStair& a, int n) {
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i].resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            cin >> a[i][j];
        }
    }
}

void intStairOutput(const intStair& a) {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    intStair a;
    int n;
    cout << "Vui long nhap kich thuoc n: ";
    cin >> n;

    intStairInput(a, n);

    cout << "Mang: " << endl;
    intStairOutput(a);

    return 0;
}
