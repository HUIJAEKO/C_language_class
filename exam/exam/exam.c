#include <stdio.h>
int main(void) {
	int lines;
	printf("input number: ");
	scanf_s("%d", &lines);

	for (int i = 1; i <= lines; i++) {
		//�� ����
		for (int j = 1; j < lines; j++) {
			printf(" ");
		}
		//���ڿ�������
		for (int j = 1; j <= i; j++) {
			printf("%d" ,j);
		}
		//���ڳ�������
		for (int j = i- 1; j >= 1; j--) {
			printf("%d", j);
		}
		
		printf("\n");
	}
	return 0;
}