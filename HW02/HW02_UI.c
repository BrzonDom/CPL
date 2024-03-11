/*
The task is to write a simple program that performs the following basic integer arithmetic operations: addition, subtraction, multiplication and division. 

You will get the operands from the standard input of your program as follows 
    <number of digits of the 1st operand>
    <1st operand>
    <operator +, -, *, />
    <number of digits of the 2nd operand>
    <2nd operand>

The operands can also be negative numbers starting with - (minus sign). 

The operands can also have more than 30 digits but less than 100 digits. Thus, more than built-in types. 

Your program is expected to print the result of the desired arithmetic operation on the standard output, and the return value shall be 0.

However, there might be situations when an unsupported operation (meaning not one of the listed above) is entered. In such situations, the program prints Error: wrong operator and returns 2. Also, any of the operands on the input might contain non-digit symbols, and those situations should result in printing Error: wrong operands and returning 3. In any other erroneous situation, print Error: unknown error and return 1. 

You can check your solution using Python, WolframAlpha or any other tool. No external library is allowed. 

    fgets() function allows flexible reading of stdin
    getchar() reads a single character from stdin
    You can find other possibly useful functions in stdio.h library
    Recall the variable-length array based on the user input from Lab02. 
*/

/*
Variables:
    int digInOp[2];
    int** inOp[2];

    char polOpSgn[3];
    int polOp[3];

    int cntCh[2];

    char inAct;
    char act;

    int flip;
    int equal;

    int dig[3];
    int** op[3];
*/

#include <stdio.h>
#include <stdlib.h>


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


int* add(int** op, int* dig) {

    int i;

    for (i = 1; i < dig[2]+1; i++) {
        op[2][dig[2]-i] = op[2][dig[2]-i] + op[0][dig[2]-i] + op[1][dig[2]-i];

        if (op[2][dig[2]-i] >= 10) {
            op[2][dig[2]-i] -= 10;
            op[2][dig[2]-i-1] += 1;
        } 
    }

    return op[2];

}

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

int* mlt(int** inOp, int** op, int* dig) {

    int i, exp;
        exp = 0;

    while (exp < dig[0]) {

        if (inOp[0][dig[0]-exp-1] != 0)
            inOp[0][dig[0]-exp-1] -= 1;
        else {
            exp += 1;
            continue;
        }
    
        for (i = 1; i < dig[1]+1; i++) {
            op[2][dig[2]-i-exp] += op[1][dig[2]-i];

            if (op[2][dig[2]-i-exp] >= 10) {
                op[2][dig[2]-i-exp] -= 10;
                op[2][dig[2]-i-exp-1] += 1;
            }
        }
    }
    return op[2];
}

int* dvs(int** op, int* dig) {

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

        /* int digInOp[] - input digits of operands */
    int digInOp[] = {0, 0};
    char scnCh;

    while (scanf("%c", &scnCh)) {
        if (scnCh == '\n') break;

            /* Error control */
        if (!(scnCh >= '0' && scnCh <= '9')) {
            printf("Error: unknown error\n");
            return 1;
        }
        else 
            digInOp[0] = digInOp[0]*10 + (scnCh - '0'); 
    }

            /* Print */
        // printf("digOp[0]: %d\n", digInOp[0]);

        /* char nL - new line, to absorb new lines from input */
    char nL;

        /* int** inOp[] - input operands stored as int arrays */
    int** inOp = (int**) malloc(2 * sizeof(int*));
        inOp[0] = (int*) malloc(digInOp[0] * sizeof(int));

        /* char polOpSgn[] - signs of polarity of operands and result */
    char polOpSgn[] = {'+', '+', '+','\0'};
        /* int polOp[] - polarity of operands and result */
    int polOp[] = {0, 0, 0};
        /* int cntCh[] - count of digits of input operand (control measure) */
    int cntCh[] = {0, 0};

    while (scanf("%c", &scnCh)) {
        if (scnCh == '\n') break;

            /* Register negative operand */
        if (cntCh[0] == 0 && scnCh == '-') {
            polOpSgn[0] = '-';
            polOp[0] = 1;
            continue;
        }
            /* Error control */
        if (!(scnCh >= '0' && scnCh <= '9')) {
            printf("Error: wrong operands\n");
            return 3;
        }
            /* input operand storing */
        inOp[0][cntCh[0]] = scnCh - '0';
        cntCh[0]++;
    }

    int i;

            /* Print */
        //     printf("polOp[0]: %c\n", polOpSgn[0]);

        //     printf("inOp[0]: ");
        //     if (polOp[0]) printf("-");

        // for (i = 0; i < digInOp[0]; i++) {
        //     printf("%d", inOp[0][i]);
        // }
    
        /* char inAct - input operation/action */
    char inAct;

    scanf( "%c", &inAct);
        // printf("\n\ninOper: %c\n", inAct);

        /* Error control */
    if (inAct != '+' && inAct != '-' && inAct != '*' && inAct != '/') {
        printf("Error: wrong operator\n");
        return 2;
    }

            scanf("%c", &nL);

    while (scanf("%c", &scnCh)) {
        if (scnCh == '\n') break;

            /* Error control */
        if (!(scnCh >= '0' && scnCh <= '9')) {
            printf("Error: unknown error\n");
            return 1;
        }
        else 
            digInOp[1] = digInOp[1]*10 + (scnCh - '0'); 
    }

            /* Print */
        // printf("\ndigOp[1]: %d\n", digInOp[1]);

        inOp[1] = (int*) malloc(digInOp[1] * sizeof(int));

    while (scanf("%c", &scnCh)) {
        if (scnCh == '\n') break;
            
            /* Register negative operand */
        if (cntCh[1] == 0 && scnCh == '-') {
            polOpSgn[1] = '-';
            polOp[1] = 1;
            continue;
        }
            
            /* Error control */
        if (!(scnCh >= '0' && scnCh <= '9')) {
            printf("Error: wrong operands\n");
            return 3;
        }

        inOp[1][cntCh[1]] = scnCh - '0';
        cntCh[1]++;
    }
            /* Print */
        // printf("polOp[1]: %c\n", polOpSgn[1]);

        // printf("inOp[1]: ");
        // if (polOp[1]) printf("-");

        // for (i = 0; i < digInOp[1]; i++) {
        //     printf("%d", inOp[1][i]);
        // }

        /* int flip - int as boolean, to simplify process if operands needed to be flipped */
    int flip = 0;

        /* char act - final operation */
    char act = inAct;


        /* Table that simplifies proccess based on polarity of operands, operation and order or operands */

        // if (polOpSgn[0] == '+' && polOpSgn[1] == '+')
    if (polOp[0] == 0 && polOp[1] == 0) {
    }
        // else if (polOpSgn[0] == '+' && polOpSgn[1] == '-')
    else if (polOp[0] == 0 && polOp[1] == 1) {
        if (inAct == '+') {act = '-';}
        else if (inAct == '-') {act = '+';}
        else if (inAct == '*') {polOpSgn[2] = '-'; polOp[2] = 1;}
        else if (inAct == '/') {polOpSgn[2] = '-'; polOp[2] = 1;}
    }
        // else if (polOpSgn[0] == '-' && polOpSgn[1] == '+')
    else if (polOp[0] == 1 && polOp[1] == 0) {
        if (inAct == '+') {act = '-'; flip = !flip;}
        else if (inAct == '-') {act = '+'; polOpSgn[2] = '-'; polOp[2] = 1;}
        else if (inAct == '*') {polOpSgn[2] = '-'; polOp[2] = 1;}
        else if (inAct == '/') {polOpSgn[2] = '-'; polOp[2] = 1;}
    }
        // else if (polOpSgn[0] == '-' && polOpSgn[1] == '-')
    else if (polOp[0] == 1 && polOp[1] == 1) {
        if (inAct == '+') {polOpSgn[2] = '-'; polOp[2] = 1;} 
        else if (inAct == '-') {act = '-'; flip = !flip;}
        // else if (inOper == '*') {oper = '*';}
    }


        /* Simplification for subtraction operation */
    if (act == '-') {
        if (digInOp[0+flip] > digInOp[1-flip]) {
            // printf("\n\ndigInOp[%d]", 0+flip);
        }
        else if (digInOp[0+flip] < digInOp[1-flip]) {
            // printf("\n\ndigInOp[%d]", 1-flip); 
            flip = !flip; 
            polOp[2] = !polOp[2];
        }
        
        else {
            for (i = 0; i < digInOp[0]; i++) {
                if (inOp[0+flip][i] > inOp[1-flip][i]) {
                    break;
                }
                else if (inOp[0+flip][i] < inOp[1-flip][i]) {
                    flip = !flip; 
                    polOp[2] = !polOp[2];
                    break;
                }
            }
            // equal = 1;
        }   
    }

    int dig[3];
        dig[0] = digInOp[0 + flip];
        dig[1] = digInOp[1 - flip]; 

        /* Estimation of needed digits */
    if (act == '+') {
        if (dig[0] > dig[1]) dig[2] = dig[0] + 1;
        else dig[2] = dig[1] + 1;
    }
    else if (act == '-') {
        if (dig[0] > dig[1]) dig[2] = dig[0];
        else dig[2] = dig[1];

    }
    else if (act == '*') 
        dig[2] = dig[0] + dig[1];
    else if (act == '/')
        dig[2] = dig[0] + 1;


        /* int** op - fianl operands stroed as int arrays (op[2] = result) */
    int** op = (int**) malloc(3 * sizeof(int*));
        op[0] = (int*) malloc(dig[2] * sizeof(int));
        op[1] = (int*) malloc(dig[2] * sizeof(int));
        op[2] = (int*) malloc(dig[2] * sizeof(int));

    for (i = 0; i < dig[2]; i++)
        op[0][i] = op[1][i] = op[2][i] = 0;

    for (i = 1; i < dig[0]+1; i++)
        op[0][dig[2]-i] = inOp[0 + flip][dig[0]-i];

    for (i = 1; i < dig[1]+1; i++)
        op[1][dig[2]-i] = inOp[1 - flip][dig[1]-i]; 


            /* Print */

        //     printf("\n\n");

        // printf("op[0]: ");
        // for (i = 0; i < dig[2]; i++)
        //     printf("%d", op[0][i]);
        // printf("\noper: %c\n", act);
        // printf("op[1]: ");
        // for (i = 0; i < dig[2]; i++)
        //     printf("%d", op[1][i]);
        // printf("\npolOp[2]: ");
        // if (polOp[2]) printf("-");
        // else printf("+");

        //     printf("\n\n");

    if (act == '+') op[2] = add(op, dig);
    else if (act == '-') op[2] = sbt(op, dig);
    else if (act == '*') op[2] = mlt(inOp, op, dig);
    else if (act == '/') op[2] = dvs(op, dig);
    
    int blank = 1;

        // printf("op[2]: ");

    if (polOp[2]) printf("-");
    for (i = 0; i < dig[2]; i++) {
        if (op[2][i] == 0 && blank) continue;
        else if (blank) blank = !blank;

        printf("%d", op[2][i]);
    } 

    free(inOp[0]);
    free(inOp[1]);
    free(inOp);

    free(op[0]);
    free(op[1]);
    free(op[2]);
    free(op);

    return 0;
}
