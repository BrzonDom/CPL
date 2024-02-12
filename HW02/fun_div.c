
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int* mul(int** op, int* digOp) {
    
    int i, j;
    int full = 1;

    while (full) {

        if (op[0][digOp[2]-1] != 0) {
            op[0][digOp[2]-1] -= 1;
        }
        else {
            for (i = 2; i < digOp[2]+1; i++) {
                if (op[0][digOp[2]-i] != 0) {
                    op[0][digOp[2]-i] -= 1;

                    for (j = (digOp[2]-i)+1; j < digOp[2]; j++) op[0][j] = 9;
                    full = 2;
                    break;
                }
            }
            full -= 1;
        }

        if (full == 0) break;

        for (i = 1; i < digOp[1]+1; i++) {
            op[2][digOp[2]-i] += op[1][digOp[2]-i];

            if (op[2][digOp[2]-i] >= 10) {
                op[2][digOp[2]-i] -= 10;
                op[2][digOp[2]-i-1] += 1;
            }
        }
    }

    // printf("\nop[2]: ");
    // for (i = 0; i < digOp[2]; i++) printf("%d", op[2][i]);

    return op[2];

}
*/

// int* mul(int** inOp, int** op, int* digOp) {

//     int i, j, exp;
//         exp = 0;

//     while (exp < digOp[0]) {

//         if (inOp[0][digOp[0]-exp-1] != 0)
//             inOp[0][digOp[0]-exp-1] -= 1;
//         else {
//             exp += 1;
//             continue;
//         }
    
//         for (i = 1; i < digOp[1]+1; i++) {
//             op[2][digOp[2]-i-exp] += op[1][digOp[2]-i];

//             if (op[2][digOp[2]-i-exp] >= 10) {
//                 op[2][digOp[2]-i-exp] -= 10;
//                 op[2][digOp[2]-i-exp-1] += 1;
//             }
//         }
//     }
//     return op[2];
// }

int* sbt(int** op, int* dig) {

    int i;

    for (i = 1; i < dig[2]+1; i++) {
        op[2][dig[2]-i] = op[2][dig[2]-i] + op[0][dig[2]-i] - op[1][dig[2]-i];

        if (op[2][dig[2]-i] < 0) {
            op[2][dig[2]-i] += 10;
            op[2][dig[2]-i-1] -= 1;
        }
    }

    return op[2];

}

int* sbt_fun(int* min, int* sub, int dig) {

    int i;

    int* res = (int*) malloc(dig * sizeof(int));
        for (i = 0; i < dig; i++) res[i] = 0;

    for (i = 1; i < dig+1; i++) {

        res[dig-i] += min[dig-i] - sub[dig-i];

        if (res[dig-i] < 0) {
            res[dig-i] += 10;
            res[dig-i-1] -= 1;
        }
    }

    return res;
}


int big(int* opB, int* opS, int dig) {

    int i;

    for (i = 0; i < dig; i++) {
        if (opB[i] > opS[i]) return 1;
        else if (opB[i] < opS[i]) return 0;
    }

    return 0;
}

int* divi(int** op, int* dig) {

    int i, j;

    int** round = (int**) malloc(3 * sizeof(int*));
        round[0] = (int*) malloc(dig[2] * sizeof(int));
        round[1] = (int*) malloc(dig[2] * sizeof(int));
        round[2] = (int*) malloc(dig[2] * sizeof(int));

    for (i = 0; i < dig[2]; i++) round[2][i] = 0;

    int fill = 2;

    while (big(op[0], round[2], dig[2])) {

        for (i = 1; i < dig[2]+1; i++) {
            round[2][dig[2]-i] += op[1][dig[2]-i];

            if (round[2][dig[2]-i] >= 10) {
                round[2][dig[2]-i] -= 10;
                round[2][dig[2]-i-1] += 1;
            }
        }

        op[2][dig[2]-1] += 1;

        for (i = 1; i < fill; i++) {
            if (op[2][dig[2]-i] >= 10) {

                if (op[2][dig[2]-fill+1] >= 10) fill++;

                op[2][dig[2]-i] -= 10;
                op[2][dig[2]-i-1] += 1;

            }
        }
    }

    for (i = 0; i < dig[2]; i++)
        round[0][i] = round[1][i] = round[2][i];
    
    round[0] = sbt_fun(round[0], op[1], dig[2]);

    round[0] = sbt_fun(op[0], round[0], dig[2]);
    round[1] = sbt_fun(round[1], op[0], dig[2]);

    if (big(round[1], round[0], dig[2])) {
        if (op[2][dig[2]-1] != 0) op[2][dig[2]-1] -= 1;
        else {
            for (i = 2; i < dig[2]+1; i++) {
                if (op[2][dig[2]-i] != 0) {
                    op[2][dig[2]-i] -= 1;

                    for (j = (dig[2]-i)+1; j < dig[2]; j++) op[2][j] = 9;
                    break;
                }
            }
        }
    }

        free(round[0]);
        free(round[1]);
        free(round[2]);
    free(round);

    return op[2];
}


int main(void) {

    printf("Division\n\n");

    int i, j, l, p, q, r, t;

    char* inStrOp[2];
        inStrOp[0] = "71709";
        inStrOp[1] = "449";

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

    digOp[2] = digOp[0] + 1;

    int** op = (int**) malloc(3 * sizeof(int*));
        op[0] = (int*) malloc(digOp[2] * sizeof(int));
        op[1] = (int*) malloc(digOp[2] * sizeof(int));
        op[2] = (int*) malloc(digOp[2] * sizeof(int));
        // op[3] = (int*) malloc(digOp[2] * sizeof(int));

    int** round = (int**) malloc(3 * sizeof(int*));
        round[0] = (int*) malloc(digOp[2] * sizeof(int));
        round[1] = (int*) malloc(digOp[2] * sizeof(int));
        round[2] = (int*) malloc(digOp[2] * sizeof(int));

    for (i = 0; i < digOp[2]; i++)
        op[0][i] = op[1][i] = op[2][i] = round[2][i] = 0;



    printf("\n\n");
        // for (i = 1; i < digOp1+1; i++) printf("%d",inOp1[digOp1-i]);
        // printf("\n");
        // for (i = 1; i < digOp1+1; i++) printf("%d",op1[digOp-i]);

    // for (i = 0; i < digOp[0]; i++) printf("%d", inOp[0][i]);
    for (i = 1; i < digOp[0]+1; i++) op[0][digOp[2]-i] = inOp[0][digOp[0]-i];

    printf("op[0]: ");
    for (i = 0; i < digOp[2]; i++) printf("%d", op[0][i]);

    for (i = 1; i < digOp[1]+1; i++) op[1][digOp[2]-i] = inOp[1][digOp[1]-i];

    printf("\nop[1]: ");
    for (i = 0; i < digOp[2]; i++) printf("%d", op[1][i]);

    printf("\nop[2]: ");
    for (i = 0; i < digOp[2]; i++) printf("%d", op[2][i]);

    printf("\nround[2]: ");
    for (i = 0; i < digOp[2]; i++) printf("%d", round[2][i]);

    printf("\n\n");

    int full, exp;
        full = 1;
        exp = 0;

    // for (i = 1; i < digOp[2]+1; i++) {
    //     op[0][digOp[2]-i] -= op[1][digOp[2]-i];

    //     if (op[0][digOp[2]-i] < 0) {
    //         op[0][digOp[2]-i] += 10;
    //         op[0][digOp[2]-i-1] -= 1;
    //     }
    // }
    
    // printf("\n\n");
    // for (i = 0; i < digOp[2]; i++) printf("%d", op[0][i]);
    int fill = 2;
    int tst = 0;

    // if (big(op[0], op[3], digOp[2])) printf("is Big");

    while (big(op[0], round[2], digOp[2])) {

        for (i = 1; i < digOp[2]+1; i++) {
            round[2][digOp[2]-i] += op[1][digOp[2]-i];

            if (round[2][digOp[2]-i] >= 10) {
                round[2][digOp[2]-i] -= 10;
                round[2][digOp[2]-i-1] += 1;
            }
        }

        tst++;

        //     printf("\n%d. op[3]: \n", tst);
        // for (l = 0; l < digOp[2]; l++)
        //     printf("%d ", op[3][l]);

        op[2][digOp[2]-1] += 1;

        for (j = 1; j < fill; j++) {
            if (op[2][digOp[2]-j] >= 10) {

                // printf("\n%d. op[3]: \n", tst);
                // for (l = 0; l < digOp[2]; l++)
                //     printf("%d ", op[2][l]);

                if (op[2][digOp[2]-fill+1] >= 10) fill++;

                op[2][digOp[2]-j] -= 10;
                op[2][digOp[2]-j-1] += 1;

                // printf("\n");
                // for (l = 0; l < digOp[2]; l++)
                //     printf("%d ", op[2][l]);
            }
        }
        
    }


    printf("\n\n\nop[2]: ");
    for (i = 0; i < digOp[2]; i++) printf("%d", op[2][i]);

    printf("\nround[2]: ");
    for (i = 0; i < digOp[2]; i++) printf("%d", round[2][i]);

    // int** round = (int**) malloc(2 * sizeof(int));
    //     round[0] = (int*) malloc(digOp[2] * sizeof(int));
    //     round[1] = (int*) malloc(digOp[2] * sizeof(int));

    for (i = 0; i < digOp[2]; i++) 
        round[0][i] = round[1][i] = round[2][i];

        // int* subtr(int* min, int* sub, int dig)
    round[0] = sbt_fun(round[0], op[1], digOp[2]);


        printf("\n\nround[0]: ");
    for (i = 0; i < digOp[2]; i++) printf("%d", round[0][i]);
    // round[0] = sub(int **op, int *dig)

        printf("\nround[1]: ");
    for (i = 0; i < digOp[2]; i++) printf("%d", round[1][i]);


    round[0] = sbt_fun(op[0], round[0], digOp[2]);
    round[1] = sbt_fun(round[1], op[0], digOp[2]);

    printf("\n\ndivident - round[0]: ");
    for (i = 0; i < digOp[2]; i++) printf("%d", round[0][i]);


    printf("\nround[1] - divident: ");
    for (i = 0; i < digOp[2]; i++) printf("%d", round[1][i]);


    if (big(round[1], round[0], digOp[2]))  { 
        printf("\n-1");

    }

    printf("\n\n");

    for (i = 0; i < digOp[2]; i++)
        op[0][i] = op[1][i] = op[2][i] = 0;


    for (i = 1; i < digOp[0]+1; i++) op[0][digOp[2]-i] = inOp[0][digOp[0]-i];

    printf("op[0]: ");
    for (i = 0; i < digOp[2]; i++) printf("%d", op[0][i]);

    for (i = 1; i < digOp[1]+1; i++) op[1][digOp[2]-i] = inOp[1][digOp[1]-i];

    printf("\nop[1]: ");
    for (i = 0; i < digOp[2]; i++) printf("%d", op[1][i]);

    printf("\nop[2]: ");
    for (i = 0; i < digOp[2]; i++) printf("%d", op[2][i]);

    op[2] = divi(op, digOp);

    printf("\n\nfin op[2]: ");
    for (i = 0; i < digOp[2]; i++) printf("%d", op[2][i]);

    // j = l = 0;
    // for (i = 1; i < 1500; i++) {
    //     op[0][digOp[2]-1] += 1;


    // }


        free(inOp[0]);
        free(inOp[1]);
    free(inOp);

        free(op[0]);
        free(op[1]);
        free(op[2]);
        // free(op[3]);
    free(op);

        free(round[0]);
        free(round[1]);
        free(round[2]);
    free(round);

    return 0;
}
