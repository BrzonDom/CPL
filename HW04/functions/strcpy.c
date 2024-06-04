#include <stdio.h>
#include <stdlib.h>
#include <string.h>


    // char *strcpy( char *dest, const char *src );
char* strcpy_f(char* dest, const char* src) {

/*  description:
        Copies the null-terminated byte string pointed to by src, including the null terminator, 
        to the character array whose first element is pointed to by dest.
        The behavior is undefined if the dest array is not large enough. The behavior is undefined if the strings overlap. 
        The behavior is undefined if either dest is not a pointer to a character array or src is not a pointer to a null-terminated byte string.        
    */

/*  parameters:
        dest = pointer to the character array to write to
        src	 = pointer to the null-terminated byte string to copy from
    */

    if (dest == NULL) return NULL;

    unsigned long int i = 0;

    while (src[i] != '\0') {

        dest[i] = src[i];
        
        i++;
    }

    dest[i] = '\0';


    return dest;

/*  return:
        returns a copy of dest
    */
}


int main(void) {

    int i;

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

    printf("sizRes: %d\n\n", sizeof(res));

    printf("Library strcpy function:\n");
    strcpy(res, str1);
        printf("\tRes1: %s\n", res);

    strcpy(res, str2);
        printf("\tRes2: %s\n", res);

    // for (i = 0; i < sizeof(res); i++)
    //     printf("%c", res[i]);

    printf("\nMy strcpy function:\n");
    strcpy_f(res, str1);
        printf("\tRes1: %s\n", res);

    strcpy_f(res, str2);
        printf("\tRes2: %s\n\n", res);
    
    // for (i = 0; i < sizeof(res); i++)
    //     printf("%c", res[i]);


    return 0;

}
