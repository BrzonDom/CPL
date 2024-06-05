#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* strchr_f(const char *str, int ch) {

    while (*str != '\0') {

        if (*str == ch) return (char*) str;

        str++;
    }

    return NULL;

}


int main(void) {

    int i, j;

    char str1[] = "Test1 Test2 abcABC 0123";
    char str2[] = "aA bB 12";
    char fin = '1';

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int siz1 = sizeof(str1);
    int siz2 = sizeof(str2);

    printf("str1: %s\n", str1);
    printf("str2: %s\n\n", str2);

    printf("len1: %d\n", len1);
    printf("siz1: %d\n\n", siz1);

    printf("len2: %d\n", len2);
    printf("siz2: %d\n\n", siz2);

    printf("fin char: %c\n\n", fin);

    char* res;

    res = strchr(str1, fin);

    printf("            1.string:   %s\n", str1);
    printf("Rest of the 1.string:   %s\n\n", res);


    res = strchr(str2, fin);

    printf("            2.string:   %s\n", str2);
    printf("Rest of the 2.string:   %s\n", res);


    return 0;

}
