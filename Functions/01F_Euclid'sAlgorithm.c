#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int maxNum(int[]);
int* minMax(int[]);

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

int* minMax(int in[]) {


}

int main() {

    int i;

    int in01[] = {2, 4};
    int in02[] = {765, 918};
    int in03[] = {101, 100};

    int maxNum01, maxNum02, maxNum03;

        // int maxNum(int in[])
    maxNum01 = maxNum(in01);
    maxNum02 = maxNum(in02);
    maxNum03 = maxNum(in03);

    printf("Max from in01: %d\n", maxNum01);
    printf("Max from in02: %d\n", maxNum02);
    printf("Max from in03: %d\n", maxNum03);

    printf("\n");

    int a, b, r, t, d;
    a = 60;
    b = 36;
    t = 1;
    r = 60 % 36;

    // r = a % b;
    // d = a / b;
    // printf("%d. (%d : %d)\t%d = %d * %d + %d", t, a, b, a, d, b, r);

    while (r != 0) {
        r = a % b;
        d = a / b;
        printf("%d. (%d : %d)  |  %d = %d * %d + %d\n", t, a, b, a, d, b, r);
        t += 1;
        a = b;
        b = r;
    }

    printf("\n\n%d", r);

    return 0;    
}