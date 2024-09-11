#include <iostream>
#include <cstring>
using namespace std;
#define MAX 50

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    void push(char c) {
        if (!isFull()) {
            arr[++top] = c;
        }
    }
    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0';
    }
    char peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return '\0';
    }
};

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool balancedBracket(const char* brackets) {
    Stack stack;          
    for (int i = 0; i < strlen(brackets); i++) {
        char c = brackets[i];
        
        if (c == '(' || c == '{' || c == '[') {
            // Push opening brackets onto the stack
            stack.push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            // Check for matching closing bracket
            if (stack.isEmpty() || !isMatchingPair(stack.peek(), c)) {
                return false;  // If stack is empty or mismatch found
            }
            stack.pop();  // Pop matching opening bracket
        }
    }
    // If stack is empty, all brackets were matched
    return stack.isEmpty();
}

int main() {
    char expression[MAX];
    cout << "Enter an expression: ";
    cin >> expression;

    if (balancedBracket(expression)) {
        cout << "Brackets are balanced.\n";
    } else {
        cout << "Brackets are not balanced.\n";
    }

    return 0;
}