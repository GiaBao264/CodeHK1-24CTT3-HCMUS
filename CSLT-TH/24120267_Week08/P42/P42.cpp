#include <stdio.h>

using namespace std;


int main()

{

	int a = 36;

	int* ptr;

	ptr = &a;

	printf("%u %u", *&ptr, &*ptr);

	return 0;

}