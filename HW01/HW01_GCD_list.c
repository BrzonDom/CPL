#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int Euclid_Fun(int*);

int Euclid_Fun(int* minMax) {
    
    int a, b, d, r;

    a = minMax[0];
    b = minMax[1];
    r = 1;

    while (r != 0) {
        r = a % b;
        d = a / b;
        // printf("(%d : %d)  |  %d = %d * %d + %d\n", a, b, a, d, b, r);
        a = b;
        b = r;
    }

    int GCD = a;

    return GCD;
}

int main() {

    int i;

    int in00[] = {2, 4};
    int in01[] = {765, 918};
    int in02[] = {101, 100};
    int in03[] = {355, 252};
    int in04[] = {403, 955};
    int in05[] = {793, 332};
    int in06[] = {275, 140};
    int in07[] = {878, 316};
    int in08[] = {859, 596};
    int in09[] = {886, 522};
    int tstIn[] = {2, 4, 123, 5,6, 23, 6, 12};

    int inList[][2] = {{2, 4}, {765, 918}, {101, 100}, {355, 252}, {403, 955}, 
                    {793, 332}, {275, 140}, {878, 316}, {859, 596}, {886, 522}};
    int inNum = (sizeof(inList)/8);

    printf("Number of input pairs: %d\n\n", inNum);

    for (i = 0; i < inNum; i++) {
        int GCD = Euclid_Fun(inList[i]);
        printf("\tGCD: %d\n", GCD);
        int out[2] = {inList[i][0]/GCD,inList[i][1]/GCD};
        
        printf("%d. %d / %d = %d / %d\n\n", (i+1), inList[i][0], inList[i][1], out[0], out[1]);
    }

    return 0;    
}