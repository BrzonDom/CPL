
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void) {

    printf("Subtraction\n\n");

    int i, j, l, p, q, r, t;

    char* inStrOp[2];
        inStrOp[0] = "200";
        inStrOp[1] = "35";

    int digOp[3];
        digOp[0] = strlen(inStrOp[0]);
        digOp[1] = strlen(inStrOp[1]);

    int** inOp = (int**) malloc(2 * sizeof(int*));
        inOp[0] = (int*) malloc(digOp[0] * sizeof(int));
        inOp[1] = (int*) malloc(digOp[1] * sizeof(int));

    printf("inOp[0] of %d digits: ", digOp[0]);
    for (i = 0; i < digOp[0]; i++) {
        inOp[0][i] = inStrOp[0][i] - '0';
        printf("%d", inOp[0][i]);
    }

    printf("\n");

    printf("inOp[1] of %d digits: ", digOp[1]);
    for (i = 0; i < digOp[1]; i++) {
        inOp[1][i] = inStrOp[1][i] - '0';
        printf("%d", inOp[1][i]);
    }

    if (digOp[0] > digOp[1]) digOp[2] = digOp[0] + 1;
    else digOp[2] = digOp[1] + 1;

    int** op = (int**) malloc(3 * sizeof(int*));
        op[0] = (int*) malloc(digOp[2] * sizeof(int));
        op[1] = (int*) malloc(digOp[2] * sizeof(int));
        op[2] = (int*) malloc(digOp[2] * sizeof(int));

    for (i = 0; i < digOp[2]; i++)
        op[0][i] = op[1][i] = op[2][i] = 0;

    printf("\n\n");
        // for (i = 1; i < digOp1+1; i++) printf("%d",inOp1[digOp1-i]);
        // printf("\n");
        // for (i = 1; i < digOp1+1; i++) printf("%d",op1[digOp-i]);

    // for (i = 0; i < digOp[0]; i++) printf("%d", inOp[0][i]);
    for (i = 1; i < digOp[0]+1; i++) op[0][digOp[2]-i] = inOp[0][digOp[0]-i];

    printf("op[0]: ");
    for (i = 0; i < digOp[2]; i++) 
        printf("%d", op[0][i]);

    for (i = 1; i < digOp[1]+1; i++) op[1][digOp[2]-i] = inOp[1][digOp[1]-i];

    printf("\nop[1]: ");
    for (i = 0; i < digOp[2]; i++) 
        printf("%d", op[1][i]);

    // printf("\nop[2]: ");
    // for (i = 0; i < digOp[2]; i++) 
    //     printf("%d", op[2][i]);

    printf("\n\n");

    for (i = 1; i < digOp[2]+1; i++) {
        op[2][digOp[2]-i] = op[2][digOp[2]-i] + op[0][digOp[2]-i] - op[1][digOp[2]-i];

        if (op[2][digOp[2]-i] < 0) {
            op[2][digOp[2]-i] += 10;
            op[2][digOp[2]-i-1] -= 1;
        }

        // printf("\n%d.", i);
        // for (j = 0; j < digOp[2]; j++) printf("%d", op[2][j]);
    }

    printf("\n\nop[2]: ");
    for (i = 0; i < digOp[2]; i++) printf("%d", op[2][i]);


        free(inOp[0]);
        free(inOp[1]);
    free(inOp);

        free(op[0]);
        free(op[1]);
        free(op[2]);
    free(op);

    return 0;
}