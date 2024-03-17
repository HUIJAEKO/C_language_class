#include <stdio.h>
int main(void)
{
	int age;

	/*use floar(4Byte)*/
	float second;

	printf("input your age(year): ");
	/*input age*/
	scanf_s("%d", &age);

	/*change age to second*/
	second = age * 3.156e7;

	printf("%d years = %f seconds", age, second);

	return 0;
}