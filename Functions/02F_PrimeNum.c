#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void primeNumListPrint(int);
int** primeNumListFunk(int);

void primeNumListPrint(int maxNum) {
    
    int i, j, curNum;

        int** primNumList = (int**) malloc(2 * sizeof(int*));
            primNumList[0] = (int*) malloc(sizeof(int));
            primNumList[1] = (int*) malloc(sizeof(int));
        
        primNumList[1][0] = 2;

    int primNumCnt = 1;

    for (curNum = 2; curNum <= maxNum; curNum++) {
        // printf("%d\n", i);
        for (i = 1; i <= primNumCnt; i++) {
            if (curNum % primNumList[1][i-1] == 0) {
                // printf("Break\n");
                break;
            }
            if (i == primNumCnt) {
                // printf("%d\n", curNum);
                primNumList[1] = (int*) realloc(primNumList[1], (primNumCnt+1) * sizeof(int));
                primNumList[1][primNumCnt] = curNum;
                primNumCnt += 1;
            }
        }
    } 

    primNumList[0][0] = primNumCnt;
    printf("Number of prime numbers: %d\n\t", primNumList[0][0]);

    for (i = 0; i < primNumCnt; i++) {
        printf("%3d ", primNumList[1][i]);

        if (!((i+1) % 10))
            printf("\n\t");
    }  

        free(primNumList[0]);
        free(primNumList[1]);
    free(primNumList);

}


int** primeNumListFunk(int maxNum) {
    
    int i, j, curNum;

        int** primeNumList = (int**) malloc(2 * sizeof(int*));
            primeNumList[0] = (int*) malloc(sizeof(int));
            primeNumList[1] = (int*) malloc(sizeof(int));
        
        primeNumList[1][0] = 2;

    int primeNumCnt = 1;

    for (curNum = 2; curNum <= maxNum; curNum++) {
        // printf("%d\n", i);
        for (i = 1; i <= primeNumCnt; i++) {
            if (curNum % primeNumList[1][i-1] == 0) {
                // printf("Break\n");
                break;
            }
            if (i == primeNumCnt) {
                // printf("%d\n", curNum);
                primeNumList[1] = (int*) realloc(primeNumList[1], (primeNumCnt+1) * sizeof(int));
                primeNumList[1][primeNumCnt] = curNum;
                primeNumCnt += 1;
            }
        }
    } 

    primeNumList[0][0] = primeNumCnt;
    // printf("Number of prime numbers: %d\n\t", primNumList[0][0]);

    // for (i = 0; i < primNumCnt; i++) {
    //     printf("%3d ", primNumList[1][i]);

    //     if (!((i+1) % 10))
    //         printf("\n");
    // }

    return primeNumList;   
}


int main() {

    int i, j, curNum;
    int maxNum = 113;

    int* primeNumList = (int*) malloc(sizeof(int));
        primeNumList[0] = 2;

    int primeNumCnt = 1;

    for (curNum = 2; curNum <= maxNum; curNum++) {
        // printf("%d\n", i);
        for (i = 1; i <= primeNumCnt; i++) {
            if (curNum % primeNumList[i-1] == 0) {
                // printf("Break\n");
                break;
            }
            if (i == primeNumCnt) {
                // printf("%d\n", curNum);
                primeNumList = (int*) realloc(primeNumList, (primeNumCnt+1) * sizeof(int));
                primeNumList[primeNumCnt] = curNum;
                primeNumCnt += 1;
            }
        }
    }
    printf("Print of \"main\"\n\n");

    for (i = 0; i < primeNumCnt; i++) {
        printf("%3d ", primeNumList[i]);

        if (!((i+1) % 10))
            printf("\n");
    }

    printf("\n\nPrint of \"primeNumListPrint\"\n\n");

        // void primeNumListPrint(int maxNum)
    primeNumListPrint(maxNum);

    printf("\n\nPrint of \"primeNumListFunk\"\n\n");

        // int** primeNumListFunk(int maxNum)
    int** primeNum2DList = primeNumListFunk(maxNum);

    printf("Number of prime numbers: %d\n\t", primeNum2DList[0][0]);

    for (i = 0; i < primeNum2DList[0][0]; i++) {
        printf("%3d ", primeNum2DList[1][i]);

        if (!((i+1) % 10))
            printf("\n\t");
    }  

        free(primeNum2DList[0]);
        free(primeNum2DList[1]);
    free(primeNum2DList);

    free(primeNumList);

    return 0;
}