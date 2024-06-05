#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    // size_t strlen( const char *str );
size_t strlen_f(const char* str) {

/*  description:
        Returns the length of the given null-terminated byte string, 
        that is, the number of characters in a character array whose 
        first element is pointed to by str up to and not including 
        the first null character.

        The behavior is undefined if str is not a pointer to a 
        null-terminated byte string.
    */

/*  parameters:
        str = pointer to the null-terminated byte string to be examined
    */

    size_t len = 0;

    while (*str != '\0') {

        len++;
        str++;
    }

    return len;

/*  return:
        The length of the null-terminated byte string str.
    */

}


int main(void) {

    char str1[] = "aAbBcCdDeEfFgGhH";
    char str2[] = "12345678901234567890";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int siz1 = sizeof(str1);
    int siz2 = sizeof(str2);

    printf("Library strlen function:\n\n");

    printf("\tstr1: %s\n", str1);
    printf("\t\tlen1: %d\n", len1);
    printf("\t\tsiz1: %d\n\n", siz1);

    printf("\tstr2: %s\n", str2);
    printf("\t\tlen2: %d\n", len2);
    printf("\t\tsiz2: %d\n\n", siz2);


    printf("\nMy strlen function:\n\n");

    len1 = strlen_f(str1);
    len2 = strlen_f(str2);

    printf("\tstr1: %s\n", str1);
    printf("\t\tlen1: %d\n\n", len1);

    printf("\tstr2: %s\n", str2);
    printf("\t\tlen2: %d\n\n", len2);


    return 0;

}
