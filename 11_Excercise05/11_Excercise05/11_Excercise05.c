#include <stdio.h>

char* string_in(const char* first, const char* second);

int main() {
    char first[30]; 
    char second[30];  

    while (1) {
        /*first*/
        printf("Enter the first: ");
        scanf_s("%s", first, 30);
        /*second*/
        printf("Enter the second: ");
        scanf_s("%s", second, 30);
        /*check*/
        char* result = string_in(first, second);
        if (result != NULL) {
            printf("found : % p\n",result);
        }
        else {
            printf("not found \n");
        }
    }

    return 0;
}
/*function*/
char* string_in(const char* first, const char* second) {
    while (*first != '\0') {
        const char* f = first;
        const char* s = second;

        /*when first == second*/
        while (*f != '\0' && *s != '\0' && *f == *s) {
            f++;
            s++;
        }

        /*when first == second, until second is \0*/
        if (*s == '\0') {
            return first;
        }

        first++;
    }

    return NULL;
}
