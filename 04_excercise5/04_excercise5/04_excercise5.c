#include <stdio.h>

int main(void)
{
	float downloadSpeed;
	float fileSize;
	float downloadTime;

	printf("fileSize(megabytes), downloadSpeed(megabits): ");
	scanf_s("%f %f", &fileSize, &downloadSpeed);

	downloadTime = fileSize * 8 / downloadSpeed;

	printf("downloadTime is %0.2f seconds \n", downloadTime);

	return 0;


}