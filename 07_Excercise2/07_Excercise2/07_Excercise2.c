#include <stdio.h>
#define NUMBER_OF_LINE 8

int main(void) {
	char ch;
	int total = 0;
	ch = getchar();
	while (ch != '#') {
		printf("%c=%d ", ch, ch);
		total++;
		/*if 8 numbers are in the same line */
		if (total % NUMBER_OF_LINE == 0)
			printf("\n");
		ch = getchar();
	}
}