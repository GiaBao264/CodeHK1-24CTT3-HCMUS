#include <stdio.h>

void addOne(int* ptrNum) {
	(*ptrNum)++;
}

int main() {
	int number;

	printf("Please enter number: ");
	scanf_s("%d", &number);

	addOne(&number);

	printf("Number after +1: %d\n", number);

	return 0;
}