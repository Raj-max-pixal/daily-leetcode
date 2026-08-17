#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    static const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    static const char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    // Max dynamic length for num <= 3999 is 15 chars (e.g., MMMDCCCLXXXVIII)
    char* roman = (char*)malloc(16 * sizeof(char));
    roman[0] = '\0';

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(roman, symbols[i]);
            num -= values[i];
        }
    }

    return roman;
}