#include <stdio.h>
#define PAY_RATE 10
#define OVERTIME 40
#define FIRST 0.15
#define NEXT 0.20
#define REST 0.25

int main(void) {
	int time;
	float grossPay;
	float taxes;
	float netPay;
	printf("enter time: ");
	scanf_s("%d", &time);
	
	/*calculate grossPay*/
	if (time <= OVERTIME)
		grossPay = time * PAY_RATE;
	else
		grossPay = (40 * PAY_RATE) + ((time - 40) * PAY_RATE * 1.5);

	/*calculate taxse*/
	if (grossPay <= 300)
		taxes = grossPay * FIRST;
	else if (grossPay <= 450)
		taxes = (300 * FIRST) + ((grossPay - 300) * NEXT);
	else
		taxes = (300 * FIRST) + (150 * NEXT) + ((grossPay - 450) * REST);

	/*calculate netPay*/
	netPay = grossPay - taxes;

	printf("gross pay is %0.2f tax is %0.2f net pay is %0.2f \n", grossPay, taxes, netPay);

}