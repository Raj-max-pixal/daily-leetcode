#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    
    // Scan character by character using the first string as a benchmark
    for (int i = 0; strs[0][i] != '\0'; i++) {
        char c = strs[0][i];
        
        // Compare current character with all other strings
        for (int j = 1; j < strsSize; j++) {
            // Check if string ended or character mismatched
            if (strs[j][i] == '\0' || strs[j][i] != c) {
                strs[0][i] = '\0'; // Truncate the first string at current length
                return strs[0];
            }
        }
    }
    
    return strs[0];
}