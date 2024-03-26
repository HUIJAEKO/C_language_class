#include <stdio.h>

int main(void) {
	
	int lower, upper;
	int sum = 0;
	int status = 1;
	
	printf("Enter the lower and upper integer limits: ");
	scanf_s("%d %d", &lower, &upper);

	/*while true*/
	while (status) {
		if (upper > lower) {
			for (int i = lower; i <= upper; i++) {
				sum += i * i;
			}
			printf("The sums of the squares from %d to %d is %d \n", lower*lower, upper*upper, sum);
			sum = 0;
			printf("Enter next set of limits: ");
			scanf_s("%d %d", &lower, &upper);
		}
		/*status will be false*/
		else {
			printf("Done");
			status = 0;
		}
	}
	return 0;
}