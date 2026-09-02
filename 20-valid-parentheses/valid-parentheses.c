#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    
    // An odd length string can never be valid
    if (len % 2 != 0) return false;

    // Allocate stack memory
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        char current = s[i];

        // Push opening brackets onto the stack
        if (current == '(' || current == '{' || current == '[') {
            stack[++top] = current;
        } 
        // Handle closing brackets
        else {
            // Stack is empty or brackets don't match
            if (top == -1) {
                free(stack);
                return false;
            }
            
            char topChar = stack[top--];
            if ((current == ')' && topChar != '(') ||
                (current == '}' && topChar != '{') ||
                (current == ']' && topChar != '[')) {
                free(stack);
                return false;
            }
        }
    }

    // String is valid only if stack is completely empty
    bool result = (top == -1);
    free(stack);
    return result;
}