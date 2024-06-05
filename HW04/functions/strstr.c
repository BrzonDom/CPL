#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {

    char str1[] = "Test1 Test2 Test3 Test4 Test5";
    char str2[] = "Object1 Object2 Test1 Test2 Object3";

    char fin[] = "Test2";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int siz1 = sizeof(str1);
    int siz2 = sizeof(str2);

    int lenFin = strlen(fin);
    int sizFin = sizeof(fin);


    printf("str1: %s\n", str1);
    printf("\tlen1: %d\n", len1);
    printf("\tsiz1: %d\n\n", siz1);

    printf("str2: %s\n", str2);
    printf("\tlen2: %d\n", len2);
    printf("\tsiz2: %d\n\n", siz2);

    printf("fin: %s\n", fin);
    printf("\tlenFin: %d\n", lenFin);
    printf("\tsizFin: %d\n\n", sizFin);

    char* res;
    
    res = strstr(str1, fin);

    printf("Res1: \n");
    printf("\t        str1: %s\n", str1);
    printf("\tRest of str1: %s\n\n", res);

    res = strstr(str2, fin);

    printf("Res2: \n");
    printf("\t        str2: %s\n", str2);
    printf("\tRest of str2: %s\n\n", res);


    return 0;

}
