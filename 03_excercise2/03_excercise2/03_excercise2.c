#include <stdio.h>
int main(void)
{
	int num;

	printf("input number: ");
	
	/*input number*/
	scanf_s("%d", &num);

	printf("number %d is %c \n", num, num);
	return 0;
}
