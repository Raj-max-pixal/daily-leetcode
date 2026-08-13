#include <stdbool.h>
#include <string.h>

// Memoization table: -1 = unvisited, 0 = false, 1 = true
int memo[25][25];

bool dp(int i, int j, const char *s, const char *p, int len_s, int len_p) {
    // Base case: pattern exhausted
    if (j == len_p) {
        return i == len_s;
    }

    // Return memoized result if available
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    // Check if current characters match
    bool first_match = (i < len_s) && (p[j] == s[i] || p[j] == '.');

    bool ans = false;

    // Handle '*' wildcard
    if (j + 1 < len_p && p[j + 1] == '*') {
        // Choice 1: Skip '*' and preceding element (0 occurrences)
        // Choice 2: Use '*' if first_match is true (1 or more occurrences)
        ans = dp(i, j + 2, s, p, len_s, len_p) || 
              (first_match && dp(i + 1, j, s, p, len_s, len_p));
    } else {
        // Standard single character match
        ans = first_match && dp(i + 1, j + 1, s, p, len_s, len_p);
    }

    memo[i][j] = ans ? 1 : 0;
    return ans;
}

bool isMatch(char *s, char *p) {
    int len_s = strlen(s);
    int len_p = strlen(p);
    
    // Initialize memo table with -1
    memset(memo, -1, sizeof(memo));

    return dp(0, 0, s, p, len_s, len_p);
}