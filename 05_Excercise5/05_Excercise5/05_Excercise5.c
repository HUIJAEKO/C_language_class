#include <stdio.h>

int main(void) {
	
	int enterNumber;
	
	printf("enter positive integer: ");
	scanf_s("%d", &enterNumber);

	int start = 1;
	int total = 0;

	while (start <= enterNumber) {
		total += start * start * start;
		start++;
	}

	printf("the result is %d \n", total);
	return 0;
}