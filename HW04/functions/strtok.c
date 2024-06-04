#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {

    int i, j;

    char str[] = "Part1 Part2 Part3 Part4 Part5";
    char splt[] = " ";

    int lenStr = strlen(str);
    int szStr = sizeof(str);

    printf("%s\n", str);
    printf("\tlen: %d\n", lenStr);
    printf("\tsiz: %d\n", szStr);

    printf("\n");

    char* res;
    i = 1;

    res = strtok(str, splt);

    while (res != NULL) {
        
        printf("%d.part: %s\n", i, res);
        i++;

        res = strtok(NULL, splt);
    }


    return 0;

}
