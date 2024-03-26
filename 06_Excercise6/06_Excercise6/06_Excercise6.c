#include <stdio.h>

int main(void) {
	int nowon = 100;
	int seoultech = 100;
	int year = 0;

	while (seoultech <= nowon) {
		nowon += (100 * 0.1);
		seoultech += (seoultech * 0.05);
		year++;
		
		if (seoultech > nowon) {
			printf("seoultech = %d \n", seoultech);
			printf("nowon = %d \n", nowon);
			printf("year = %d \n", year);
		}
	}
}