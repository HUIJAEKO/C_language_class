#include <stdio.h>
void sort(double *num1, double *num2, double *num3);

int main(void) {
	double a, b, c;
    printf("enter three double number: ");
	scanf_s("%lf %lf %lf", &a, &b, &c);
	sort(&a, &b, &c);
    printf("%.6lf, %.6lf, %.6lf \n", a,b,c);
    return 0;
}

/*sort three numbers*/
void sort(double *num1, double *num2, double *num3) {
    double temp;
    if (*num1 > *num2) {
        temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }
    if (*num1 > *num3) {
        temp = *num1;
        *num1 = *num3;
        *num3 = temp;
    }
    if (*num2 > *num3) {
        temp = *num2;
        *num2 = *num3;
        *num3 = temp;
    }
}

