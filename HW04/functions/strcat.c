#include <stdio.h>
#include <string.h>


char* strcat_f(char* dest, const char* src) {

    unsigned long int i = 0, j = 0;

    while (dest[i] != '\0') i++;

    while (src[j] != '\0') {

        dest[i] = src[j];

        i++;
        j++;
    }

    dest[i] = '\0';


    return dest;
}


int main(void) {

    char str1[20] = "Test1";
    char str2[] = "Test2";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int siz1 = sizeof(str1);
    int siz2 = sizeof(str2);

    int lenRes = len1 + len2 + 1;

    printf("len1: %d\n", len1);
    printf("siz1: %d\n\n", siz1);

    printf("len2: %d\n", len2);
    printf("siz2: %d\n\n", siz2);

    char res[50];

    printf("Str1: %s\n", str1);
    printf("Str2: %s\n\n", str2);

    strcat(str1, str2);
        printf("Res: %s\n", str1);


    return 0;

}