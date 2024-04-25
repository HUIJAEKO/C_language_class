#include <stdio.h>
int main(void) {
	int lines;
	printf("input number: ");
	scanf_s("%d", &lines);

	for (int i = 1; i <= lines; i++) {
		//앞 공백
		for (int j = 1; j < lines; j++) {
			printf(" ");
		}
		//숫자오름차순
		for (int j = 1; j <= i; j++) {
			printf("%d" ,j);
		}
		//숫자내림차순
		for (int j = i- 1; j >= 1; j--) {
			printf("%d", j);
		}
		
		printf("\n");
	}
	return 0;
}