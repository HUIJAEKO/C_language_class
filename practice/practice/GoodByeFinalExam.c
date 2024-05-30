#include<stdio.h>

int main(void) {
	int value1 = 44;
	int arr[4];
	int value2 = 88;
	int i;

	printf("%d %d", value1, value2);
	for (i = 0; i <= 4; i++) {
		arr[i] = 2 * i + 1;
	
		for (i = -1; i < 7; i++) {
			printf("%d, %d", value1, value2);
		}
	}
}
