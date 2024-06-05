#include <stdio.h>
#include <stdlib.h>
#include <string.h>


    // char *strchr( const char *str, int ch );
char* strchr_f(const char *str, int ch) {

/*  description:
        Finds the first occurrence of ch (after conversion to char as if 
        by (char)ch) in the null-terminated byte string pointed to by str 
        (each character interpreted as unsigned char). The terminating null 
        character is considered to be a part of the string and can be 
        found when searching for '\0'.
    */

/*  parameters:
        str	= pointer to the null-terminated byte string to be analyzed
        ch  = character to search for
    */

    while (*str != '\0') {

        if (*str == ch) return (char*) str;

        str++;
    }

    return NULL;

/*  return:            
        Pointer to the found character in str, or null pointer if no such 
        character is found.
    */

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
    printf("\tlen1: %d\n", len1);
    printf("\tsiz1: %d\n\n", siz1);

    printf("str2: %s\n", str2);
    printf("\tlen2: %d\n", len2);
    printf("\tsiz2: %d\n\n", siz2);

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
