#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* strcpy_f(char* dest, const char* src) {

    if (dest == NULL) return NULL;

    unsigned long int i = 0;

    while (src[i] != '\0') {

        dest[i] = src[i];
        
        i++;
    }

    dest[i] = '\0';

    return dest;
    
}


int main(void) {

    char str1[] = "Test1";
    char str2[] = "Test2 string";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int siz1 = sizeof(str1);
    int siz2 = sizeof(str2);

    char res[50];

    printf("len1: %d\n", len1);
    printf("siz1: %d\n\n", siz1);

    printf("len2: %d\n", len2);
    printf("siz2: %d\n\n", siz2);

    printf("Str1: %s\n", str1);
    printf("Str2: %s\n\n", str2);

    strcpy(res, str1);
        printf("Res1: %s\n", res);

    strcpy(res, str2);
        printf("Res2: %s\n\n", res);


    return 0;

}
