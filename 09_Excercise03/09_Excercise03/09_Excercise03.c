#include<stdio.h>
double harmonic(double a, double b);

int main(void) {
	double number1, number2;
	double result;
	printf("enter two double number: ");
	/*when user enter two numbers*/
	if (scanf_s("%lf %lf", &number1, &number2) == 2) {
		/*numbers > 0*/
		if (number1 > 0 && number2 > 0) {
			result = harmonic(number1, number2);
			printf("the result is %.3lf", result);
		}
		else {
			printf("enter again");
		}
	}
	return 0;
}

/*function*/
double harmonic(double a, double b) {
	/*inverse of input numbers*/
	double inverseA = 1.0 / a;
	double inverseB = 1.0 / b;
	/*average of inverse numbers*/
	double inverseAverage = (inverseA + inverseB) / 2.0;
	/*inverse of average*/
	double harmonicNumber = 1.0 / inverseAverage;

	return harmonicNumber;
}