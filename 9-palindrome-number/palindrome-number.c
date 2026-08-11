#include <stdbool.h>

bool isPalindrome(int x) {
    // Base cases:
    // 1. Negative numbers are not palindromes (e.g., -121 -> 121-)
    // 2. Numbers ending with 0 (except 0 itself) are not palindromes (e.g., 10 -> 01)
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    // For even number of digits: x == revertedNumber (e.g., 1221 -> x = 12, revertedNumber = 12)
    // For odd number of digits: x == revertedNumber / 10 (e.g., 121 -> x = 1, revertedNumber = 12)
    return x == revertedNumber || x == revertedNumber / 10;
}