#include <stdio.h>
#define WEEKS 7

int main(void) {

	int enterDays;

	while (1) {
		printf("enter days(if non-positive, program will be done): ");
		scanf_s("%d", &enterDays);
		while (enterDays >= 0) {
			int weeks = enterDays / WEEKS;
			int days = enterDays % WEEKS;
			printf("%d is %d weeks, %d days \n", enterDays, weeks, days);
			break;
		}
		while (enterDays < 0) {
			return 0;
		}
	}
}