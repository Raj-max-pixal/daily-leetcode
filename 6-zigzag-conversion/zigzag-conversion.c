#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);

    // Edge case: row height 1 or s is shorter than numRows
    if (numRows == 1 || numRows >= len) {
        char* result = (char*)malloc((len + 1) * sizeof(char));
        strcpy(result, s);
        return result;
    }

    char* result = (char*)malloc((len + 1) * sizeof(char));
    int idx = 0;
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < len; j += cycleLen) {
            // Add vertical column element
            result[idx++] = s[j + i];
            
            // Add diagonal element (not applicable for top and bottom rows)
            int diagIdx = j + cycleLen - i;
            if (i != 0 && i != numRows - 1 && diagIdx < len) {
                result[idx++] = s[diagIdx];
            }
        }
    }
    
    result[idx] = '\0'; // Null-terminate the string
    return result;
}