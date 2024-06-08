#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <direct.h>

#define NUMBER 6
#define MAX_NUMBER 45
#define PATH 256

void student_name();
void start_print();
int contains(int* number, int num, int length);
void random_number(int* number);
int match_count(int* user, int* winning);
void result(int* user, int* winning, int count);
int has_duplicates(int* numbers, int length);

void single_mode_keyboard_rule();
void single_mode_keyboard();
void keyboard_result(int* user, int* winning, int count);

void single_mode_file_rule();
void single_mode_file();
void file_input_result(int* user, int* winning, int count);

void multi_mode();
void multi_mode_file_rule();
void display_result(int* user, int* winning, int count, FILE* fp, int i);
void calculate_prizes(int count, int* prize_counts, int* total_spent, int* total_earned);

int main(void) {
    /*start*/
    while (1) {
        /*clear screen*/
        system("cls");

        student_name();
        start_print();

        int mode;

        if (scanf_s("%d", &mode) != 1 || mode < 1 || mode > 4) {
            system("cls");
            continue;
        }

        /*select a mode*/
        switch (mode) {
        case 1:
            single_mode_keyboard();
            break;
        case 2:
            single_mode_file();
            break;
        case 3:
            multi_mode();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}

/*student number and name*/
void student_name() {
    printf("                                19100031 Huijae Ko\n");
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
    printf("                       select a mode: ");
}

/*make 6 random number*/
void random_number(int* number) {
    int i, num;
    for (i = 0; i < NUMBER; i++) {
        do {
            /*assign 1~45 to num*/
            num = (rand() % MAX_NUMBER) + 1;
        } while (contains(number, num, i)); /*duplication test*/
        number[i] = num;
    }
}

/*duplication test(with specific charactor)*/
int contains(int* number, int num, int length) {
    for (int i = 0; i < length; i++) {
        if (number[i] == num) {
            return 1;
        }
    }
    return 0;
}

/*duplication test for file input*/
int has_duplicates(int* numbers, int length) {
    for (int i = 0; i < length; i++) {
        if (contains(numbers, numbers[i], i)) {
            return 1;  
        }
    }
    return 0;  
}

/*compare user choice numbers and random numbers*/
int match_count(int* user, int* winning) {
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
void result(int* user, int* winning, int count) {
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
        char input[50];
        int isValid;

        while (1) {
            fgets(input, sizeof(input), stdin);
            /*enter Q to exit*/
            if (input[0] == 'Q' || input[0] == 'q') {
                system("cls");
                return;
            }
            /*enter A to get random numbers*/
            if (input[0] == 'A' || input[0] == 'a') {
                random_number(user);
                break;
            }
            else {
                /*split a string into " " token*/
                char* token = strtok(input, " ");
                int index = 0;
                isValid = 1;

                while (token != NULL && index < NUMBER) {
                    /*make string to int type*/
                    int num = atoi(token);
                    if (num < 1 || num > MAX_NUMBER || contains(user, num, index)) {
                        isValid = 0;
                        break;
                    }
                    /*save number to array*/
                    user[index++] = num;
                    token = strtok(NULL, " ");
                }

                if (isValid && index == NUMBER) {
                    break;
                }
                else {
                    printf("           Enter valid numbers, or 'Q' to quit: ");
                }
            }
        }

        /*make random number, compare and print result*/
        random_number(winning);
        int count = match_count(user, winning);
        result(user, winning, count);
        printf("                   Press Enter to play again, or 'Q' to quit\n");
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'Q' || input[0] == 'q') {
            system("cls");
            return;
        }
    }
}

/*keyboard input result*/
void keyboard_result(int* user, int* winning, int count) {
    student_name();
    single_mode_keyboard_rule();
    result(user, winning, count);
}

/*print single file mode rule*/
void single_mode_file_rule() {
    printf("---------------------------------------------------------------------------------\n");
    printf("                   2) single game mode(using file input)\n");
    printf("                          pick 6 - of - 45 game\n");
    printf("           Rule #1: A PLAY means placing 6 unique numbers from 1 to 45 per each line.\n");
    printf("           Rule #2: They must be separated by whitespace\n");
    printf("           Rule #3: Typing single 'A' means random 6 picks\n");
    printf("           Rule #4: An input text file contains multiple lines\n");
    printf("           Rule #5: A line with invalid format must be ignored\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("           Enter the input text filename(e.g.input.txt).Input 'Q' for quit\n");
}

/*single mode(file input)*/
void single_mode_file() {
    while (1) {
        system("cls");

        student_name();
        single_mode_file_rule();

        FILE* fp = NULL;

        char fname[PATH];
        char input[256];


        /*enter file path and check if file exists*/
        while (1) {
            fgets(fname, sizeof(fname), stdin);
            /*remove newline*/
            fname[strcspn(fname, "\n")] = '\0';

            /*enter Q to exit*/
            if (fname[0] == 'Q' || fname[0] == 'q') {
                system("cls");
                return;
            }

            /*open file*/
            fp = fopen(fname, "r");

            /*file doesn't exist*/
            if (fp == NULL) {
                printf("           Enter correct file name: ");
            }
            else {
                break;
            }
        }

        /*if file exists*/
        if (fp != NULL) {
            /*read file contents line by line with fgets function*/
            while (fgets(input, sizeof(input), fp)) {
                int user[NUMBER];
                char* token = NULL;

                int index = 0;
                int isValid = 1;

                /*context for strtok function*/
                char* context = NULL;

                /*split a string into " " token*/
                token = strtok(input, " ");
                while (token != NULL && index < NUMBER) {
                    if (token[0] == 'A' || token[0] == 'a') {
                        random_number(user);
                        index = NUMBER;  
                        break;
                    }
                    else {
                        /*make string to int type*/
                        int num = atoi(token);
                        if (num < 1 || num > MAX_NUMBER) {
                            isValid = 0;
                            break;
                        }
                        /*save number to array*/
                        user[index++] = num;
                    }
                    token = strtok(NULL, " ");
                }

                /*if valid numbers or A*/
                if ((isValid && index == NUMBER) && !has_duplicates(user, NUMBER)) {
                    /*make winning number*/
                    int winning[NUMBER];
                    random_number(winning);

                    /*compare and print result*/
                    int count = match_count(user, winning);
                    for (int i = 0; i < NUMBER; i++) {
                        printf("%d ", user[i]);
                    }
                    printf("\n");
                    file_input_result(user, winning, count);
                    printf("    Press Enter to continue");
                    getchar();
                }

                
            }
            /*close file*/
            fclose(fp);
            char input[2];
            fgets(input, sizeof(input), stdin);
            /*if enter Q*/
            if (input[0] == 'Q' || input[0] == 'q') {
                system("cls");
                return;
            }
        }
    }
}

/*file input result*/
void file_input_result(int* user, int* winning, int count) {
    system("cls");
    student_name();
    single_mode_file_rule();
    result(user, winning, count);
}

/*print multi mode rules*/
void multi_mode_file_rule() {
    printf("---------------------------------------------------------------------------------\n");
    printf("                       3) multi game simulation mode\n");
    printf("                           pick 6 - of - 45 game\n");
    printf("  Rule #1: A PLAY means placing 6 unique numbers from 1 to 45 per each line\n");
    printf("  Rule #2: Rule #2: The total number of PLAYs from 1, 000 to 1, 000, 000 must be given\n");
    printf("  Rule #3: Each WIN is displayed with winning numbers and my random picks\n");
    printf("  Rule #4: The followings are displayed at the end of simulation :\n");
    printf("  Number of WINSs regarding each prize, and the money earned and spent totally for PLAYs\n");
    printf("  Rule #5: Every PLAY is stored in output text file\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("         Enter the input text filename(e.g.input.txt).Input 'Q' for quit\n");      
}

/*multi mode*/
void multi_mode() {
    int exit_program = 0;

    while (!exit_program) {
        system("cls");

        student_name();
        multi_mode_file_rule();
           
        char fname[256];
        int plays = 0;
        FILE* fp = NULL;

        //Input the output file name
        printf("         Input the output file name: ");
        fgets(fname, sizeof(fname), stdin);
        fname[strcspn(fname, "\n")] = '\0';

        // Open file
        fp = fopen(fname, "w");
        if (fp == NULL) {
            printf("Failed to open the file.\n");
            continue;
        }

        // Input the number of plays
        while (1) {
            printf("         Input the number of plays (range: 1,000 to 1,000,000): ");
            scanf("%d", &plays);
            while (getchar() != '\n');
            if (plays >= 1000 && plays <= 1000000) {
                break;
            }
            else {
                printf("         Invalid number of plays. Please enter a value between 1,000 and 1,000,000.\n");
            }
        }


        /*make array and values to store count of prize and total money*/
        int prize_counts[4] = {0, 0, 0, 0};
        int total_spent = 0; 
        int total_earned = 0; 

        /*save result to txt file and calculate money*/
        for (int i = 0; i < plays; i++) {
            int user[NUMBER];
            int winning[NUMBER];

            random_number(user);
            random_number(winning);

            /*display result for each play and save*/
            int count = match_count(user, winning);
            display_result(user, winning, count, fp, i);

            /*calculate prizes and total money*/
            calculate_prizes(count, prize_counts, &total_spent, &total_earned);
        }

        fclose(fp);

        // display summary
        printf("\n                 Summary\n");
        printf("         Number of 1st prizes: %d\n", prize_counts[0]);
        printf("         Number of 2nd prizes: %d\n", prize_counts[1]);
        printf("         Number of 3rd prizes: %d\n", prize_counts[2]);
        printf("         Number of 4th prizes: %d\n", prize_counts[3]);
        printf("         Total money spent: %d won\n", total_spent);
        printf("         Total money earned: %d won\n", total_earned);

        printf("\n         Do you want to exit? (1: Yes, 0: No): ");
        scanf_s("%d", &exit_program);
    }
}

/*display multi mode result*/
void display_result(int* user, int* winning, int count, FILE* fp, int i) {
    fprintf(fp, "\n[%d]              Your numbers: ", i+1);
    for (int j = 0; j < NUMBER; j++) {
        fprintf(fp, "%d ", user[j]);
    }
    fprintf(fp, "\n[%d]              Winning numbers: ", i+1);
    for (int j = 0; j < NUMBER; j++) {
        fprintf(fp, "%d ", winning[j]);
    }
    fprintf(fp, "\n                  Matches: %d\n", count);
}

/*calculate prizes and total money*/
void calculate_prizes(int count, int* prize_counts, int* total_spent, int* total_earned) {
    /*increment prize count*/
    switch (count) {
    case 6:
        prize_counts[0]++;
        *total_earned += 1000000000;
        break;
    case 5:
        prize_counts[1]++;
        *total_earned += 1000000;
        break;
    case 4:
        prize_counts[2]++;
        *total_earned += 50000;
        break;
    case 3:
        prize_counts[3]++;
        *total_earned += 5000;
        break;
    default:
        break;
    }
    /*Update total money spent*/
    *total_spent += 1000;
}




