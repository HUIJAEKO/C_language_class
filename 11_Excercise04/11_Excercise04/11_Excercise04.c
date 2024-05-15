 #include <stdio.h>
int is_within(char c, const char * ch);

int main(void) {
	char string[30];
	char check;

	/*string*/
	printf("Enter the string: ");
	scanf_s("%s", string, 30);
	/*charactor*/
	printf("Enter the charactor to check: ");
	scanf_s("%c", &check);

	/*check*/
	if (is_within(check, string)) {
		printf("string have %c", check);
	}
	else {
		printf("string don't have %c", check);
	}
}
/*function*/
int is_within(char c, char * ch) {
	while (*ch != '\0') {
		if (*ch == c) {
			return 1;
		}
		ch++;
	}
	return 0;
}