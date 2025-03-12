#include <stdio.h>

int main() {
    int a[] = { 1, 2, 3, 4, 5 };
    int* ptr;

    ptr = a;
    printf("%d ", *(ptr + 1));

    return 0;
}