#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100          // Maximum stack size
#define NAME_LENGTH 50   // Maximum name length

char stack[MAX][NAME_LENGTH];  // Stack for storing names
int top = -1;  // Stack top index
int stack_size;  // Actual stack size

// Function to get a valid integer input
int get_valid_int(const char *prompt, int min, int max) {
    char buffer[20];  // Input buffer
    int num;

    while (1) {
        printf("%s", prompt);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error reading input. Try again.\n");
            continue;
        }

        // Validate input: it must be an integer
        if (sscanf(buffer, "%d", &num) == 1 && num >= min && num <= max) {
            return num;
        }

        printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
    }
}

// Function to get a valid name input
void get_valid_name(char *name, int max_length) {
    while (1) {
        if (fgets(name, max_length, stdin) == NULL) {
            printf("Error reading input. Try again.\n");
            continue;
        }

        // Remove trailing newline character
        name[strcspn(name, "\n")] = '\0';

        // Check if the name is empty
        if (strlen(name) == 0) {
            printf("Error: Name cannot be empty. Try again: ");
            continue;
        }

        // Ensure the name contains only valid characters (letters, spaces)
        int valid = 1;
        for (int i = 0; name[i] != '\0'; i++) {
            if (!isalpha(name[i]) && name[i] != ' ') {
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf("Error: Name must contain only letters and spaces. Try again: ");
            continue;
        }

        return;
    }
}

// Function to push a name onto the stack
void push() {
    if (top >= stack_size - 1) {
        printf("Error: Stack is full!\n");
        return;
    }

    top++;
    printf("Enter name: ");
    get_valid_name(stack[top], NAME_LENGTH);
}

// Function to pop a name from the stack
void pop() {
    if (top == -1) {
        printf("Error: Stack is empty!\n");
        return;
    }

    printf("Popped name: %s\n", stack[top]);
    top--;
}

// Function to display all names in the stack
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack contents:\n");
    for (int i = top; i >= 0; i--) {
        printf("%s\n", stack[i]);
    }
}

// Function to peek at the top name in the stack
void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top name in stack: %s\n", stack[top]);
}

int main() {
    // Get a valid stack size from the user
    stack_size = get_valid_int("Enter stack size (1 to 100): ", 1, MAX);

    int choice;
    do {
        printf("\n1. Push a name\n");
        printf("2. Pop a name\n");
        printf("3. Display stack\n");
        printf("4. Peek at top name\n");
        printf("5. Exit\n");
        choice = get_valid_int("Enter your choice: ", 1, 5);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
