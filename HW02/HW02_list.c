
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* add(int* op, int* op1, int* op2, int digOp) {

    int i;

    for (i = 1; i < digOp+1; i++) {
        op[digOp-i] = op[digOp-i] + op1[digOp-i] + op2[digOp-i];

        if (op[digOp-i] >= 10) {
            op[digOp-i] -= 10;
            op[digOp-i-1] += 1;
        }
    }

    // for (i = 0; i < digOp; i++)
    //     printf("%d", op[i]);

    return op;

}

int* sub(int* op, int* op1, int* op2, int digOp) {
        
    int i;

    for (i = 1; i < digOp+1; i++) {
        op[digOp-i] = op[digOp-i] + op1[digOp-i] - op2[digOp-i];

        if (op[digOp-i] < 0) {
            op[digOp-i] += 10;
            op[digOp-i-1] -= 1;
        }
    }

    // for (i = 0; i < digOp; i++)
    //     printf("%d", op[i]);

    return op;

}

int* sum(int* op, int* op1, int digOp1, int* op2, int digOp) {

    int i, j, l;

    for (i = 0; i < digOp1; i++) {
        for (j = 0; j < op1[digOp1-i]; j++) {
            for (l = 1; l < digOp+1; l++) {
                op[digOp-l-i] = op[digOp-l-i] + op2[digOp-l];

                if (op[digOp-l-i] >= 10) {
                    op[digOp-l-i] -= 10;
                    op[digOp-l-i-1] += 1;
                }
            }
        }
    }

    return op;
}


int main(void) {

    char inStrOp1[] = "1231343451";
    char polOp1 = ' ';
    char inStrOp2[] = "9834508";
    char polOp2 = ' ';

    char operation = '-';

    int digOp1 = strlen(inStrOp1);
    int digOp2 = strlen(inStrOp2);

    int i;

    int* inOp1 = (int*) malloc(digOp1 * sizeof(int));
    int* inOp2 = (int*) malloc(digOp2 * sizeof(int));

    printf("inOp1 of %d digits: ", digOp1);
    for (i = 0; i < digOp1; i++) {
        inOp1[i] = inStrOp1[i] - '0';
        printf("%d", inOp1[i]);
    }

    printf("\n\n");

    printf("inOp2 of %d digits: ", digOp2);
    for (i = 0; i < digOp2; i++) {
        inOp2[i] = inStrOp2[i] - '0';
        printf("%d", inOp2[i]);
    }

    printf("\n\n");

    int digOp;
    int* op; int* op1; int* op2;

    if (operation == '+' || operation == '-') {
        if (digOp1 > digOp2) digOp = digOp1 + 1;
        else digOp = digOp2 + 1;
    }
    else if (operation == '*') {
        digOp = digOp1 + digOp2;
    }

    op = (int*) malloc((digOp) * sizeof(int));
    op1 = (int*) malloc((digOp) * sizeof(int));
    op2 = (int*) malloc((digOp) * sizeof(int));

    for (i = 0; i < digOp; i++)
        op[i] = op1[i] = op2[i] = 0;

    for (i = 1; i < digOp1+1; i++) op1[digOp-i] = inOp1[digOp1-i];

    printf("op1: ");
    for (i = 0; i < digOp; i++) printf("%d",op1[i]);
    // printf("\n");
    // for (i = 1; i < digOp1+1; i++) printf("%d", inOp1[digOp1-i]);
    // printf("\n");
    // for (i = 1; i < digOp1+1; i++) printf("%d", op1[digOp-i]);
    // printf("\n");
    // for (i = 1; i < digOp+1; i++) printf("%d", op1[digOp-i]);

    printf("\n\n");

    for (i = 1; i < digOp2+1; i++) op2[digOp-i] = inOp2[digOp2-i];

    printf("op2: ");
    for (i = 0; i < digOp; i++) printf("%d", op2[i]);


    printf("\n\n");

    op = add(op, op1, op2, digOp);

    printf("op add: ");
    for (i = 0; i < digOp; i++) printf("%d", op[i]);

    printf("\n\n");

    for (i = 0; i < digOp; i++) op[i] = 0;

    op = sub(op, op1, op2, digOp);

    printf("op sub: ");
    for (i = 0; i < digOp; i++) printf("%d", op[i]);

    // 01 241 177 959
    //  1 241 177 959

    free(inOp1);
    free(inOp2);

    free(op);
    free(op1);
    free(op2);

    return 0;
}
