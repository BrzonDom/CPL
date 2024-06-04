#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {

    char str1[] = "1234567890abcdefgh";
    char str2[] = "012345";

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


    int lenRes = strspn(str1, str2);
        printf("lenRes: %d\n", lenRes);


    return 0;

}
