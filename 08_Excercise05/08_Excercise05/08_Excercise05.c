#include <stdio.h>
int main(void) {
	int lowNumber = 1;
	int highNumber = 100;
	int guessNumber = 50;
	char answer;

	printf("choose integer 1~100\n");
	printf("input y(yes) or h(high) or l(low)\n");
	printf("%d :\n", guessNumber);

	while ((answer = getchar()) != 'y') {
		if (answer == '\n') {
			continue;
		}
		if (answer == 'h') {
			highNumber = guessNumber - 1;
		}else if (answer == 'l') {
			lowNumber = guessNumber + 1;
		}
		else {
			printf("only y,h,l \n");
		}
		guessNumber = (lowNumber + highNumber) / 2;
		printf("%d :\n", guessNumber);
	}

	return 0;
}