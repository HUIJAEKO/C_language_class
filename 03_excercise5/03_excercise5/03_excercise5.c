#include <stdio.h>
#include <float.h>

int main(void)
{
	/*example : float*/
	
	/*max value*/
	float max = FLT_MAX;
	printf("max is %f\n", max);

	/*make overflow*/
	float overflow = max*10000.0f;
	printf("overflow is %f\n", overflow);

	/*min value*/
	float min = -FLT_MAX;
	printf("min is %f\n", min);

	/*make underflow*/
	float underflow = min*10000.0f;
	printf("underflow is %f\n", underflow);

	return 0;
}