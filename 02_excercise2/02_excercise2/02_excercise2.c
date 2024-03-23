#include <stdio.h>
int main(void)
{
	int a, b;
	a = 5;
	b = 4;
	a = b;
	b = a;
	printf("%d %d.\n", a, b);
}
