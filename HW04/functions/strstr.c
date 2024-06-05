#include <stdio.h>
#include <stdlib.h>
#include <string.h>


size_t strlen_f(const char* str) {

    size_t len = 0;

    while (*str != '\0') {

        len++;
        str++;
    }

    return len;

}


int main(void) {

    char str1[] = "aAbBcCdDeEfFgGhH";
    char str2[] = "12345678901234567890";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int siz1 = sizeof(str1);
    int siz2 = sizeof(str2);

    printf("str1: %s\n", str1);
    printf("\tlen1: %d\n", len1);
    printf("\tsiz1: %d\n\n", siz1);

    printf("str2: %s\n", str2);
    printf("\tlen2: %d\n", len2);
    printf("\tsiz2: %d\n\n", siz2);


    return 0;

}
