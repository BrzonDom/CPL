#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {

    int i, j;

    char str[] = "Part1 Part2 Part3 Part4 Part5";
    char splt[] = " ";

    int lenStr = strlen(str);
    // for (i = 0; i < lenStr; i++)
    //     printf("%c", str[i]);

    // printf("\n\n");

    int szStr = sizeof(str);
    // for (i = 0; i < szStr; i++)
    //     printf("%c", str[i]);


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

        // for (j = 0; j < szStr; j++)
        //     printf("%c", str[j]);
        // printf("\n\n");

        res = strtok(NULL, splt);
    }


    return 0;

}
