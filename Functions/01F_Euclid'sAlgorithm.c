#include <stdio.h>

int maxNum(int[]);
int Euclid_Fun(int*);


int maxNum(int in[]) {
    int maxNum;

    if (in[0] < 0) in[0] *= -1;
    if (in[1] < 0) in[1] *= -1;

    if (in[0] < in[1])
        maxNum = in[1];
    else
        maxNum = in[0];

    return maxNum;
}


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

    int in01[] = {2, 4};
    int in02[] = {765, 918};
    int in03[] = {101, 100};

    // int* inLst[] = {&in01, &in02, &in03};
    int* inLst[] = {in01, in02, in03};

    int inNum = sizeof(inLst)/sizeof(inLst[0]);

    // printf("Size: %d\n\n", inNum);

    for (i = 0; i < inNum; i++) {
        printf("%d.Input list: {%d, %d}\n\n", i+1, inLst[i][0], inLst[i][1]);

        printf("\t1.Num: %d\n", inLst[i][0]);
        printf("\t2.Num: %d\n", inLst[i][1]);
        printf("\n");

        int a, b, r, t, d;

            a = inLst[i][0];
            b = inLst[i][1];
            t = 1;
            r = a % b;

            while (r != 0) {
                r = a % b;
                d = a / b;
                printf("\t\t%d. (%3d : %3d)  |  %3d = %3d * %3d + %2d\n", t, a, b, a, d, b, r);
                t += 1;
                a = b;
                b = r;
            }
            printf("\n\n");
    }

    // r = a % b;
    // d = a / b;
    // printf("%d. (%d : %d)\t%d = %d * %d + %d", t, a, b, a, d, b, r);

    return 0;    
}
