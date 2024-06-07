#include <stdio.h>

#define NUMBER 6
#define MAX_NUMBER 45

int duplication(int* array, int num, int length);

void student_name();
void start_print();
void single_mode_keyboard_rule();

void random_number(int* number);
int match_count(int* user, int* winning);
void result(int* user, int* winning, int count);

void single_mode_keyboard();
void single_mode_file();
void multi_mode();

int main(void) {
	/*start*/
	while (1) {
		/*clear screen*/
		system("cls");

		student_name();
		start_print();

		int mode;

		/*no number*/
		if (scanf_s("%d", &mode) != 1) {
			system("cls");
			continue; 
		}

		if(mode < 1 || mode > 5) {
			system("cls");
			continue;
		}

		/*select a mode*/
		switch (mode) {
			case 1:
				single_mode_keyboard();
				break;
			case 2:
				/*single_mode_file();*/
				break;
			case 3:
				/*multi_mode(); */
				break;
			case 4:
				exit(0);
		}
	}
	return 0;
}

/*student number and name*/
void student_name() {
	printf("				19100031 Huijae Ko\n");
	printf("                              [Lotto 6/45 Simulator]\n");
}

/*print when start this program*/
void start_print() {
	printf("-----------------------------------------------------------------------------\n");
	printf("                       1) single game mode (keyboard input)\n");
	printf("                       2) single game mode (file input)\n");
	printf("                       3) multi game simulation mode \n");
	printf("                       4) exit\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("select a mode: ");
}

/*make 6 random number*/
void random_number(int * number) {
	int i, num;
	for (i = 0; i < NUMBER; i++) {
		do {
			/*assign 1~45 to num*/
			num = (rand() % MAX_NUMBER) + 1;
		} while (contains(number, num, i)); /*duplication test*/
		number[i] = num;
	}
}

/*duplication test*/
int contains(int * number, int num, int length) {
	for (int i = 0; i < length; i++) {
		if (number[i] == num) {
			return 1;
		}
	}
	return 0; 
}

/*compare user choice numbers and random numbers*/
int match_count(int * user, int * winning) {
	int count = 0;
	for (int i = 0; i < NUMBER; i++) {
		for (int j = 0; j < NUMBER; j++) {
			if (user[i] == winning[j]) {
				count++;
			}
		}
	}
	return count;
}

/*print result*/
void result(int * user, int * winning, int count) {
	printf("\n------------------------------------Result---------------------------------------\n");
	printf("                      Your numbers: ");
	for (int i = 0; i < NUMBER; i++) {
		printf("%d ", user[i]);
	}
	printf("\n                      Winning numbers: ");
	for (int i = 0; i < NUMBER; i++) {
		printf("%d ", winning[i]);
	}
	printf("\n                      Matches: %d\n", count);

	switch (count) {
	case 6:
		printf("                     you won 1st prize (1 billion won)\n");
		printf("---------------------------------------------------------------------------------\n");
		break;
	case 5:
		printf("                     you won 2nd prize (1 million won)\n");
		printf("---------------------------------------------------------------------------------\n");
		break;
	case 4:
		printf("                     you won 3rd prize (50 thousand won)\n");
		printf("---------------------------------------------------------------------------------\n");
		break;
	case 3:
		printf("                     you won 4th prize (5 thousand won)\n");
		printf("---------------------------------------------------------------------------------\n");
		break;
	case 2:
	case 1:
	case 0: 
		printf("                                  you lose\n");
		printf("---------------------------------------------------------------------------------\n");
		break;
	default:
		printf("---------------------------------------------------------------------------------\n");
	}
}

/*print single keyboard mode rule*/
void single_mode_keyboard_rule() {
	printf("---------------------------------------------------------------------------------\n");
	printf("                 1) single game mode(using keyboard input)\n");
	printf("                          pick 6 - of - 45 game\n");
	printf("           Rule #1: A PLAY means picking 6 unique numbers from 1 to 45\n");
	printf("           Rule #2: They must be separated by whitespace\n");
	printf("           Rule #3: Typing single 'A' means random 6 picks\n");
	printf("---------------------------------------------------------------------------------\n");
	printf("           pick 6 numbers(input 'A' for random pick or 'Q' for quit)\n");
}

/*single mode(keyboard input)*/
void single_mode_keyboard() {
	while (1) {
		system("cls");

		student_name();
		single_mode_keyboard_rule();

		int user[NUMBER];
		int winning[NUMBER];
		char input[20];

		printf("\n   Your number: ");

		while (1) {
			fgets(input, sizeof(input), stdin);

			if (input[0] == 'Q' || input[0] == 'q') {
				system("cls");
				return;
			}

			if (input[0] == 'A' || input[0] == 'a') {
				random_number(user);
				break;
			}
		}

		random_number(winning);
		int count = match_count(user, winning);
		result(user, winning, count);
		printf("                     Press Enter to play again, or 'Q' to quit\n");
		fgets(input, sizeof(input), stdin);
		if (input[0] == 'Q' || input[0] == 'q') {
			system("cls");
			return;
		}
		else {
		}
	}
}

void single_mode_file() {

}

void multi_mode() {

}

