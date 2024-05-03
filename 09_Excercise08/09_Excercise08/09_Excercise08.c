#include <stdio.h>
#define SIZE 30	
void fibonacci(int* list);

int main(void) {
	/*size = 30*/
	int list[SIZE];
	fibonacci(list);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}

/*fibonacci function*/
void fibonacci(int* list) {
	list[0] = 0;
	list[1] = 1;
	for (int i = 2; i < SIZE; i++) {
		list[i] = list[i - 1] + list[i - 2];
	}
}