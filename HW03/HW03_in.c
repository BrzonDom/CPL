#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(const void* word1, const void* word2) {
    
    return strcmp(*(char**) word1, *(char**) word2);
}

char** sort_lst_fun(char** word_lst, int wordNum) {

    qsort(word_lst, wordNum, sizeof(char*), compare);

    return word_lst;
}

char** same_lst_fun(char** word_lst, int wordNum) {

    int i, j;

    int difCnt, sameCnt, skip;
        difCnt = sameCnt = skip = 0;

    char** same_lst = (char**) malloc(sizeof(char*));

    for (i = 0; i < wordNum; i++) {
        for (j = 0; j < difCnt; j++)
            if (!strcmp(word_lst[i], same_lst[j])) {skip = 1; break;}

        if (skip) {skip = 0; continue;}

        if (difCnt) {
            same_lst = realloc(same_lst, (difCnt+1) * sizeof(char*));
            
        }

        same_lst[difCnt] = (char*) malloc((strlen(word_lst[i])+1) * sizeof(char));
        strcpy(same_lst[difCnt], word_lst[i]);

        // for (i = i+1; j < wordNum; j++) {
        //     if (!strcmp(word_lst[i], word_lst[j])) 
        // }
        difCnt++;
    }    

    return same_lst;
}

int* same_cnt_fun(char** word_lst, int wordNum) {

    int i, j;

    int difCnt, sameCnt, skip;
        difCnt = sameCnt = skip = 0;

    int* sameCnt_list = (int*) malloc(sizeof(int));
        sameCnt_list[0] = 1;

    for (i = 0; i < wordNum; i++) {
        for (j = 0; j < i; j++)
            if (!strcmp(word_lst[i], word_lst[j])) {skip = 1; break;}
        
        if (skip) {skip = 0; continue;}

        if (difCnt) {
            sameCnt_list = realloc(sameCnt_list, (difCnt+1) * sizeof(int));
                sameCnt_list[difCnt] = 1;
        }

        for (j = i+1; j < wordNum; j++)
            if (!strcmp(word_lst[i], word_lst[j]))
                sameCnt_list[difCnt]++;

        difCnt++;

    }

    return sameCnt_list;
}

int main(void) {

    char StrInLoc[] = "pubB0.in";
    char InLoc[sizeof(StrInLoc) + 7] = "data\\";
    strcat(InLoc, StrInLoc);
        printf("Source: %s\n\n", InLoc);
    
    FILE *In;	In = fopen(InLoc, "r");

        if (NULL == In) {
            printf("file can't be opened \n");
            exit(1);	
        }

    int i, j;

    int wordCnt, digCnt, dataCnt, maxDig;
        wordCnt = digCnt = dataCnt = maxDig = 0;
    char chScn;

    char* data = (char*) malloc(sizeof(char));

    char** word_lst = (char**) malloc(sizeof(char*));
        word_lst[0] = (char*) malloc(sizeof(char));

    int* word_dig_lst = (int*) malloc(sizeof(int));


    while (fscanf(In, "%c", &chScn) != EOF) {

        data[dataCnt] = chScn;

        dataCnt++;
        data = realloc(data, (dataCnt+1) * sizeof(char));

        if (chScn == ' ' || chScn == '\n') {

            word_dig_lst[wordCnt] = digCnt;
            if (digCnt > maxDig) maxDig = digCnt;

            word_lst[wordCnt] = realloc(word_lst[wordCnt], (digCnt+1) * sizeof(char));
            word_lst[wordCnt][digCnt] = '\0';

            wordCnt++;
            digCnt = 0;

            if (chScn == '\n') break;

            word_lst = realloc(word_lst, (wordCnt+1) * sizeof(char*));
                word_lst[wordCnt] = (char*) malloc(sizeof(char));

            word_dig_lst = realloc(word_dig_lst, (wordCnt+1) * sizeof(int));

            
            continue;
        }
        else {

            if (digCnt) word_lst[wordCnt] = realloc(word_lst[wordCnt], (digCnt+1) * sizeof(char));
            
            word_lst[wordCnt][digCnt] = chScn;
            digCnt++;
        }
    }
    
    fclose(In);
    dataCnt--;

    int wordNum = wordCnt;

    printf("Data: ");
    for (i = 0; i < dataCnt; i++)
        printf("%c", data[i]);

    printf("\n\nNum. of data char.: %d\n", dataCnt);
    printf("Num. of words: %d\n", wordNum);
    printf("Max digit: %d\n\n", maxDig);

    printf("Words with digits: \n");
    for (i = 0; i < wordNum; i++)
        printf("\t%d.\t\t[%d] %s\n", i, word_dig_lst[i], word_lst[i]);

    char** sort_lst = sort_lst_fun(word_lst, wordNum);

    printf("\nSorted words with digits: \n");
    for (i = 0; i < wordNum; i++)
        printf("\t%d.\t\t[%d] %s\n", i, strlen(sort_lst[i]), sort_lst[i]);

    free(data);

    for (i = 0; i < wordNum; i++)
        free(word_lst[i]);
    free(word_lst);

    free(word_dig_lst);

    // free(sort_lst);

    // for (i = 0; i < wordNum; i++)
    //     free(sort_lst[i]);
    // free(sort_lst);

    return 0;

}
