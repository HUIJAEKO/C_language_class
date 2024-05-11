#include<stdio.h>
void reverse(int array[], int arrayReverse[]);

int main(void) {
	int array[5] = { 1, 2, 3, 4, 5 };
	int arrayReverse[5];

	reverse(array, arrayReverse);

	for (int i = 0; i < 5; i++) {
		printf("%d ", arrayReverse[i]);
	}
}
/*reverse function*/
void reverse(int array[], int arrayReverse[]) {
	for (int i = 0, j = 4; i < 5; i++, j--) {
		arrayReverse[j] = array[i];
	}
}