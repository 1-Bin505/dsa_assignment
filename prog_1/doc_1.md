# Parentheses Balancing Program

## Overview
This program checks the validity and number of parenthesis in the mathematical expression provided as input by the user.

## Data Structures

### Stack
- **Type**: Character array
- **Declaration**: `char stack[MAX]`
- **Top pointer**: Integer variable `top` initialized to -1, indicating an empty stack
- **Purpose**: Stores opening brackets temporarily while scanning the expression

The stack follows the Last-In-First-Out (LIFO) principle, making it ideal for matching nested brackets.

## Functions Implemented

### 1. `void push(char data)`
**Purpose**: Adds a character to the top of the stack.

**Parameters**:
- `data`: The character to be pushed onto the stack (opening bracket)

**Functionality**:
- Checks if the stack is full (overflow condition when `top == MAX - 1`)
- If not full, increments `top` and stores the character at that position
- Prints "Overflow" message if the stack is full

### 2. `char pop()`
**Purpose**: Removes and returns the character from the top of the stack.

**Parameters**: None

**Return Value**: 
- The character at the top of the stack
- Returns `'\0'` (null character) if the stack is empty

**Functionality**:
- Checks if the stack is empty (`top == -1`)
- If not empty, returns the character at `top` and decrements `top`
- If empty, returns null character indicating underflow

### 3. `void parentheses(char *exp)`
**Purpose**: Validates whether the brackets in the expression are balanced and properly matched.

**Parameters**:
- `exp`: Pointer to the character array (string) containing the expression to be checked

**Functionality**:
- Resets the stack by setting `top = -1`
- Iterates through each character in the expression
- For opening brackets `(`, `{`, `[`: pushes them onto the stack
- For closing brackets `)`, `}`, `]`:
  - Checks if stack is empty (indicates closing bracket without opening)
  - Pops the top character from the stack
  - Verifies if the popped opening bracket matches the current closing bracket
  - Reports mismatch if brackets don't correspond
- After scanning the entire expression:
  - If stack is empty: prints "Balanced"
  - If stack has remaining elements: prints "Unbalanced" with the unclosed opening bracket

## Main Method Organization

The `main()` function is organized as follows:

1. **Variable Declaration**: Declares a character array `exp[MAX]` to store the user's input expression

2. **User Input**: Prompts the user to enter an expression containing parentheses and reads it using `scanf()`

3. **Validation**: Calls the `parentheses()` function with the input expression to check balance

4. **Program Termination**: Returns 0 to indicate successful execution

The main function serves as the entry point and handles user interaction, delegating the actual validation logic to the `parentheses()` function.


## Sample Output
**Example 1:**
<img width="414" height="55" alt="Screenshot 2026-02-10 at 8 15 44 PM" src="https://github.com/user-attachments/assets/237bf5f4-5193-4366-a65a-fe2f43f8d2ef" />

**Example 2:**
<img width="418" height="54" alt="Screenshot 2026-02-10 at 8 17 08 PM" src="https://github.com/user-attachments/assets/5d7cd1fd-1212-453a-9295-0fc3978f52e8" />


**Example 3:**
<img width="359" height="55" alt="Screenshot 2026-02-10 at 8 17 41 PM" src="https://github.com/user-attachments/assets/aea9ca2a-158c-48fc-b854-cdc2f80c583d" />
