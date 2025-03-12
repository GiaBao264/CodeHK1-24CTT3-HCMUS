#include <stdio.h>

using namespace std;


int main()

{

	int i = 25;

	int* j;

	int** k;

	j = &i;

	k = &j;

	printf("%u %u %u ", k, *k, **k);

	return 0;

}