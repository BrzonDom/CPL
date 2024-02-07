#include <stdio.h>

int Euclid_Fun(int*);

int Euclid_Fun(int* minMax) {
    
    int a, b, d, r;

    a = minMax[0];
    b = minMax[1];
    r = 1;

    while (r != 0) {
        r = a % b;
        d = a / b;
        printf("(%3d : %3d)  |  %3d = %2d * %3d + %2d\n", a, b, a, d, b, r);
        a = b;
        b = r;
    }

    int GCD = a;

    return GCD;
}

int main() {

    int inNum[2];
    
    scanf("%d %*c %d", &inNum[0], &inNum[1]);
    printf("\tContent: %d / %d", inNum[0], inNum[1]);

    printf("\n\n");

    printf("\t\t1.Num.: %d\n", inNum[0]);
    printf("\t\t2.Num.: %d\n", inNum[1]);

        // int Euclid_Fun(int* minMax)
    int GCD = Euclid_Fun(inNum);

    printf("\nGCD: %d\n\n", GCD);

    int outNum[2];
        outNum[0] = inNum[0] / GCD;
        outNum[1] = inNum[1] / GCD;

    printf("%3d / %3d = %2d / %2d", inNum[0], inNum[1], outNum[0], outNum[1]);

    return 0;    
}
