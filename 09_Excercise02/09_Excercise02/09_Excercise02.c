#include<stdio.h>
void printFunction(char ch, int number, int line);

int main(void) {
	char inputCh;
	int inputNumber, inputLine;
	printf("Enter ch, number, line: ");
	/*whem user enter three elements*/
	if (scanf_s("%c %d %d", &inputCh, 1, &inputNumber, &inputLine) == 3) {
		if (inputNumber > 0 && inputLine > 0) {
			printFunction(inputCh, inputNumber, inputLine);
		}
		else {
			printf("enter again");
		}
	}
	return 0;
}

/*print function*/
void printFunction(char ch, int number, int line) {
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < number; j++) {
			printf("%c ", ch);
		}
		printf("\n");
	}
}