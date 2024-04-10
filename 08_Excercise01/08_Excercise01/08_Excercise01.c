#include <stdio.h>
int main(void) {
	int count = 0;
	int ch;

	printf("Ctrl + Z : exit \n");

	while ((ch = getchar()) != EOF) {
		if (ch == '\n')
			count--;
		count++;
	}
	

	printf("number of charactors : %d\n", count);
	return 0;
}