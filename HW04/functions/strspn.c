#include <stdio.h>
#include <stdlib.h>
#include <string.h>


    // size_t strspn( const char* dest, const char* src );
size_t strspn_f(const char* dest, const char* src) {

/*  description:
        Returns the length of the maximum initial segment (span) of the byte string pointed to by dest,
        that consists of only the characters found in byte string pointed to by src.
    */

/*  parametrs:   
        dest = pointer to the null-terminated byte string to be analyzed
        src	 = pointer to the null-terminated byte string that contains the characters to search for
    */

    size_t len = 0, i, j;

    size_t lenDest = 0;
        while (dest[lenDest] != '\0') lenDest++;

    size_t lenSrc = 0;
        while (src[lenSrc] != '\0') lenSrc++; 
    
    int match = 0;

    for (i = 0; i < lenDest; i++) {

        match = 0;

        for (j = 0; j < lenSrc; j++) {
            if (dest[i] == src[j]) {
                match = 1;
                break;
            }
        }

        if (!match) break;
        else len++;

    }


    return len;

/*  return:
        The length of the maximum initial segment that contains only characters from byte string pointed to by src.
    */
}


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
