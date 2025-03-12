#include <stdio.h>

using namespace std;


int main()

{

	int num = 10;

	printf("num = %d address of num = %u", num, &num);

	num++;

	printf("\n num = %d address of num = %u", num, &num);

	return 0;

}