#include <stdio.h>
#include <stdlib.h>
#include <string.h>


    // char *strpbrk( const char *dest, const char *breakset );
char* strpbrk_f(const char* dest, const char* breakset) {

/*  description:
        Scans the null-terminated byte string pointed to by dest for 
        any character from the null-terminated byte string pointed to 
        by breakset, and returns a pointer to that character.
    */

/*  parameters:
        dest     = pointer to the null-terminated byte string to be analyzed
        breakset = pointer to the null-terminated byte string that contains the characters to search for
    */

    if (dest == NULL || breakset == NULL)
        return NULL;

    const char *tempset;

    while (*dest != '\0') {

        tempset = breakset;

        while (*tempset != '\0') {

            if (*dest == *tempset)
                return (char*) dest;

            tempset++;
        }
        dest++;
    }


    return NULL;

/*  return:
        Pointer to the first character in dest, that is also in breakset, 
        or null pointer if no such character exists.
    */

}


int main(void) {

    int i, j;

    char str1[] = "Test1 Test2 abcABC 0123";
    char str2[] = "aA bB 12";

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

    char* res;

    res = strpbrk(str1, str2);

    printf("First character found: %c\n\n", *res);

    printf("Rest of the string: %s\n", res);


    return 0;

}
