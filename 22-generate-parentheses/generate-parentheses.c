#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char** result, char* current, int open, int close, int n, int* returnSize, int* index) {
    // Base case: current string length equals 2 * n
    if (open == n && close == n) {
        result[*index] = (char*)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*index], current);
        (*index)++;
        return;
    }

    // Add an opening parenthesis if we have remaining open count
    if (open < n) {
        current[open + close] = '(';
        current[open + close + 1] = '\0';
        backtrack(result, current, open + 1, close, n, returnSize, index);
    }

    // Add a closing parenthesis if closing count is less than open count
    if (close < open) {
        current[open + close] = ')';
        current[open + close + 1] = '\0';
        backtrack(result, current, open, close + 1, n, returnSize, index);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    // Allocate maximum possible memory (Catalan number bounds, max ~1430 for n=8)
    int maxCombinations = 5000;
    char** result = (char**)malloc(maxCombinations * sizeof(char*));
    char* current = (char*)malloc((2 * n + 1) * sizeof(char));
    
    int index = 0;
    current[0] = '\0';

    backtrack(result, current, 0, 0, n, returnSize, &index);

    *returnSize = index;
    free(current);
    return result;
}