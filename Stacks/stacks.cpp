#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 100; // Maximum size of the stack
    char array[MAX_SIZE];            // Array to store stack elements (use char instead of int)
    int top_idx;                     // Index of the top element

public:
    // Constructor to initialize the stack
    Stack() : top_idx(-1) {}

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top_idx == -1;
    }

    // Function to check if the stack is full
    bool isFull() const {
        return top_idx == MAX_SIZE - 1;
    }

    // Push operation: Add an element to the top of the stack
    void Push(char element) { // Changed to accept char
        if (isFull()) {
            cout << "Overflow occurred! Cannot push to a full stack." << endl;
            return;
        }
        array[++top_idx] = element; // Increment top_idx first, then assign the value
    }

    // Pop operation: Remove and return the element on the top of the stack
    char Pop() { // Changed to return char
        if (isEmpty()) {
            cout << "Underflow occurred! Cannot pop from an empty stack." << endl;
            return '\0'; // Return null character to indicate failure
        }
        return array[top_idx--]; // Decrement top_idx after accessing the element
    }

    // Peak operation: Display the contents of the top element of the stack
    char Peak() const { // Changed to return char
        if (isEmpty()) {
            cout << "Stack is empty! No top element to display." << endl;
            return '\0'; // Return null character to indicate failure
        }
        return array[top_idx];
    }

    // Clear operation: Release the memory allocated by the stack
    void Clear() {
        top_idx = -1; // Reset top_idx to indicate the stack is empty
        cout << "Stack cleared." << endl;
    }
};

// Function to check if the braces in the input string are balanced
bool bracesCheck(Stack& s, const string& inputStr) { // Pass stack by reference
    for (char ch : inputStr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.Push(ch); // Push opening braces onto the stack
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) { // If stack is empty, no matching opening brace
                return false;
            }

            char top = s.Pop(); // Pop the top element
            // Check if the popped element matches the current closing brace
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // Mismatched braces
            }
        }
    }
    // If the stack is empty, all braces were matched
    return s.isEmpty();
}

int main() {
    Stack stack;
    string inputString;

    cout << "Enter a string with braces: ";
    getline(cin, inputString); // Read the entire line

    if (bracesCheck(stack, inputString)) {
        cout << "1.	This expression is correct." << endl;
    } else {
        cout << "2.	This expression is NOT correct e.g. error at character # 10. ‘{‘- not closed." << endl;
    }

    return 0;
}