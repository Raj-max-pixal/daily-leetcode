#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mapping of digits 2-9 to corresponding telephone letters
const char* MAPPING[] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

void backtrack(char* digits, int index, char* currentCombination, char** result, int* returnSize) {
    // Base case: full combination formed
    if (digits[index] == '\0') {
        currentCombination[index] = '\0';
        result[*returnSize] = (char*)malloc((index + 1) * sizeof(char));
        strcpy(result[*returnSize], currentCombination);
        (*returnSize)++;
        return;
    }

    int digit = digits[index] - '0';
    const char* letters = MAPPING[digit];

    // Try all letters corresponding to current digit
    for (int i = 0; letters[i] != '\0'; i++) {
        currentCombination[index] = letters[i];
        backtrack(digits, index + 1, currentCombination, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    int len = strlen(digits);

    if (len == 0) {
        return NULL;
    }

    // Maximum possible combinations = 4^len
    int maxCombinations = 1;
    for (int i = 0; i < len; i++) {
        maxCombinations *= 4;
    }

    char** result = (char**)malloc(maxCombinations * sizeof(char*));
    char* currentCombination = (char*)malloc((len + 1) * sizeof(char));

    backtrack(digits, 0, currentCombination, result, returnSize);

    free(currentCombination);
    return result;
}