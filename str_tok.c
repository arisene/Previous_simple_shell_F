#include "main.h"


char *str_tok(char *str, const char *delimiters) {
    static char *token = NULL;
    char *start = str;

    /* If we're starting with a new string, set the token to the start*/
    if (start != NULL)
        token = start;

    /* If we're at the end of the string, return NULL to indicate no more tokens*/
    if (token == NULL)
        return NULL;

    /* Find the beginning of the token by skipping leading delimiters*/
    while (*token != '\0' && strchr(delimiters, *token) != NULL)
        token++;

    /* If we're at the end of the string, return NULL to indicate no more tokens*/
    if (*token == '\0') {
        token = NULL;
        return NULL;
    }

    /* Save the starting position of the token*/
    start = token;

    /* Find the end of the token */
    while (*token != '\0' && strchr(delimiters, *token) == NULL)
        token++;

    /* If we're at the end of the string, set token to NULL to indicate no more tokens*/
    if (*token == '\0')
        token = NULL;
    else
        *token++ = '\0';  /* Replace the delimiter and move token to the next position*/

    return start;
}


