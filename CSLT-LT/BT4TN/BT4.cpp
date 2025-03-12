#include <iostream>

#define N 20

using namespace std;

int row(string board[][N], int n) {
    int count = 0;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (board[i][j] == "x") {
                count++;
                if (count >= 5) {
                    total++;
                }
            }
            else {
                count = 0;
            }
        }
    }
    return total;
}

int column(string board[][N], int n) {
    int count = 0;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (board[j][i] == "x") {
                count++;
                if (count >= 5) {
                    total++;
                }
            }
            else {
                count = 0;
            }
        }
    }
    return total;
}

int diagonallyLeft(string board[][N], int n) {
    int count = 0;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[j][j + i] == "x") {
                count++;
                if (count >= 5) {
                    total++;;
                }
            }
            else {
                count = 0;
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[j][i - j] == "x") {
                count++;
                if (count >= 5) {
                    total++;;
                }
            }
            else {
                count = 0;
            }
        }
    }
    return total;
}

int diagonallyRight(string board[][N], int n) {
    int count = 0;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[j][j - i] == "x") {
                count++;
                if (count >= 5) {
                    total++;;
                }
            }
            else {
                count = 0;
            }
        }
    }
    return total;
}

int main() {
    int n;
    string board[N][N];
    cout << "Please enter array size (n x n): ";
    cin >> n;

    if (0 <= n && n <= 20) {
        cout << "Enter the elements of array:";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }
        cout << "There are " << column(board, n) + row(board, n) + diagonallyLeft(board, n) + diagonallyRight(board, n) << " rows in total with x >= 5." << endl;
    }
    else {
        cout << "Please enter array size <= 20" << endl;
    }

    system("pause");
    return 0;
}