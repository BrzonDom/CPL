#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static char* iter;

    // char *strtok( char *str, const char *delim ); 
char* strtok_f (char* str, const char* delim) {

/*  description:
        1) Finds the next token in a null-terminated byte string pointed to by str. The separator characters are identified by null-terminated byte string pointed to by delim.
        This function is designed to be called multiple times to obtain successive tokens from the same string.
        If str is not a null pointer, the call is treated as the first call to strtok for this particular string. The function searches for the first character which is not contained in delim.
        If no such character was found, there are no tokens in str at all, and the function returns a null pointer.
        If such character was found, it is the beginning of the token. The function then searches from that point on for the first character that is contained in delim.
        If no such character was found, str has only one token, and future calls to strtok will return a null pointer
        If such character was found, it is replaced by the null character '\0' and the pointer to the following character is stored in a static location for subsequent invocations.
        The function then returns the pointer to the beginning of the token
        If str is a null pointer, the call is treated as a subsequent call to strtok: the function continues from where it left in previous invocation. The behavior is the same as if the previously stored pointer is passed as str.
        The behavior is undefined if either str or delim is not a pointer to a null-terminated byte string.
    */

/* parameters:
        str	  = pointer to the null-terminated byte string to tokenize
        delim =	pointer to the null-terminated byte string identifying delimiters
    */

    char* token;

    if (str == NULL)
        str = iter;

    str += strspn(str, delim);

    if (*str == '\0') {
        iter = str;
        return NULL;
    }

    token = str;
    str = strpbrk(token, delim);

    if (str == NULL)
        iter = strchr(token, '\0');
    else {
        *str = '\0';
        iter = str + 1;
    }

    return token;

/*  return:
        Returns pointer to the beginning of the next token or a null pointer if there are no more tokens.
    */
}


int main(void) {

    int i, j;

    char str[] = "Part1 Part2 Part3 Part4 Part5";
    char splt[] = " ";

    int lenStr = strlen(str);
    int szStr = sizeof(str);

    printf("%s\n", str);
    printf("\tlen: %d\n", lenStr);
    printf("\tsiz: %d\n", szStr);

    printf("\n");

    char* res;
    i = 1;

    res = strtok(str, splt);

    while (res != NULL) {
        
        printf("%d.part: %s\n", i, res);
        i++;

        res = strtok(NULL, splt);
    }


    return 0;

}
