#include <stdio.h>
#define GALLON_TO_LITERS 3.785
#define MILE_TO_KILOMETERS 1.609

int main(void)
{
	float milesTraveled;
	float gallonOfGasoline;
	float miles_per_gallon;

	printf("enter the number of miles traveled and the number of gallons of gasoline: ");
	scanf_s("%f %f", &milesTraveled, &gallonOfGasoline);	
	miles_per_gallon = milesTraveled / gallonOfGasoline;
	printf("miles per gallon is %0.1f \n", miles_per_gallon);

	float liters = gallonOfGasoline * GALLON_TO_LITERS;
	float kilometers = milesTraveled * MILE_TO_KILOMETERS;
	float liters_per_100kilometers = liters / 100 * kilometers;

	printf("liters per 100kilometers is %0.1f \n", liters_per_100kilometers);
	
	return 0;
}