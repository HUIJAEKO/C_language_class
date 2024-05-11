#include<stdio.h>
void copy_arr(double target[], double array[], int num);
void copy_ptr(double target[], double array[], int num);
void copy_ptrs(double target[], double array[], double * last);

int main(void) {
	int num = 5;
	double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double target1[5];
	double target2[5];
	double target3[5];

	copy_arr(target1, source, num);
	copy_ptr(target2, source, num);
	copy_ptrs(target3, source, &source[num-1]);

	/*print first copy*/
	for (int i = 0; i < sizeof(target1) / sizeof(target1[0]); i++) {
		printf("%.1f ", target1[i]);
	}
	printf("\n");
	/*print second copy*/
	for (int i = 0; i < sizeof(target2) / sizeof(target2[0]); i++) {
		printf("%.1f ", target2[i]);
	}
	printf("\n");
	/*print last copy*/
	for (int i = 0; i < sizeof(target3) / sizeof(target3[0]); i++) {
		printf("%.1f ", target3[i]);
	}
	printf("\n");

	return 0;
}

/*first copy function*/
void copy_arr(double target[], double array[], int num) {
	for (int i = 0; i < num; i++) {
		target[i] = array[i];
	}
}
/*second copy function*/
void copy_ptr(double target[], double array[], int num) {
	for (int i = 0; i < num; ++i) {
		*(target + i) = *(array + i);
	}
}
/*last copy function*/
void copy_ptrs(double target[], double array[], double * last) {
	for (double* ptrs = array; ptrs <= last; ++ptrs, ++target) {
		*target = *ptrs;
	}
}