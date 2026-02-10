# Infix to Postfix Conversion and Evaluation Program

## Overview
This program converts a mathematical expression from infix notation (e.g., `3+4*2`) to postfix notation (e.g., `342*+`) and then evaluates the postfix expression to compute the result. The program uses two separate stacks: one for operators during conversion and another for values during evaluation.

## Data Structures

### Operator Stack
- **Type**: Character array
- **Declaration**: `char op_stack[MAX]`
- **Size**: Maximum of 70 elements (defined by `MAX`)
- **Top pointer**: Integer variable `top_op` initialized to -1
- **Purpose**: Temporarily stores operators and parentheses during infix to postfix conversion

### Value Stack
- **Type**: Integer array
- **Declaration**: `int val_stack[MAX]`
- **Size**: Maximum of 70 elements (defined by `MAX`)
- **Top pointer**: Integer variable `top_val` initialized to -1
- **Purpose**: Stores operand values during postfix expression evaluation

Both stacks follow the Last-In-First-Out (LIFO) principle.

## Functions Implemented

### 1. `void push_op(char op)`
**Purpose**: Pushes an operator or parenthesis onto the operator stack.

**Parameters**:
- `op`: The character (operator or parenthesis) to be pushed

**Functionality**:
- Checks for stack overflow condition
- Increments `top_op` and stores the operator
- Prints overflow message if stack is full

### 2. `char pop_op()`
**Purpose**: Removes and returns the top operator from the operator stack.

**Parameters**: None

**Return Value**: 
- The character at the top of the operator stack
- Returns `'\0'` if stack is empty (underflow)

**Functionality**:
- Checks for underflow condition
- Returns the top operator and decrements `top_op`
- Prints underflow message if stack is empty

### 3. `int push_val(char val)`
**Purpose**: Pushes a numeric value onto the value stack.

**Parameters**:
- `val`: The integer value to be pushed

**Return Value**: 
- Returns 0 on success
- Returns -1 on overflow

**Functionality**:
- Checks for stack overflow
- Increments `top_val` and stores the value
- Returns appropriate status code

### 4. `int pop_val()`
**Purpose**: Removes and returns the top value from the value stack.

**Parameters**: None

**Return Value**: 
- The integer at the top of the value stack
- Returns -1 if stack is empty (underflow)

**Functionality**:
- Checks for underflow condition
- Returns the top value and decrements `top_val`
- Prints underflow message if stack is empty

### 5. `int prec(char op)`
**Purpose**: Returns the precedence level of an operator.

**Parameters**:
- `op`: The operator character

**Return Value**: 
- 3 for exponentiation (`^`)
- 2 for multiplication and division (`*`, `/`)
- 1 for addition and subtraction (`+`, `-`)
- 0 for invalid operators

**Functionality**:
- Uses a switch statement to assign precedence values
- Higher values indicate higher precedence

### 6. `bool is_right_assoc(char op)`
**Purpose**: Determines if an operator is right-associative.

**Parameters**:
- `op`: The operator character

**Return Value**: 
- `true` if the operator is `^` (exponentiation)
- `false` otherwise

**Functionality**:
- Returns boolean value indicating associativity
- Used during conversion to handle operators with same precedence

### 7. `int operator_eval(int a, int b, char op)`
**Purpose**: Performs the arithmetic operation specified by the operator on two operands.

**Parameters**:
- `a`: First operand (left operand)
- `b`: Second operand (right operand)
- `op`: The operator to apply

**Return Value**: 
- The result of the arithmetic operation

**Functionality**:
- Uses switch statement to identify the operation
- Performs addition, subtraction, multiplication, division, or exponentiation
- For exponentiation, uses a loop to compute the power
- Returns 0 for invalid operators

### 8. `void infix_to_postfix(char* infix, char* postfix)`
**Purpose**: Converts an infix expression to postfix notation using the Shunting Yard algorithm.

**Parameters**:
- `infix`: Pointer to the input infix expression string
- `postfix`: Pointer to the output postfix expression string

**Functionality**:
- Iterates through each character of the infix expression
- **For digits**: Directly appends to postfix expression
- **For '('**: Pushes onto operator stack
- **For ')'**: Pops operators until matching '(' is found
- **For operators**: 
  - Pops operators with higher or equal precedence (considering associativity)
  - Pushes the current operator onto the stack
- After processing all characters, pops remaining operators
- Prints the resulting postfix expression

### 9. `int postfix_eval(char* postfix)`
**Purpose**: Evaluates a postfix expression and returns the result.

**Parameters**:
- `postfix`: Pointer to the postfix expression string

**Return Value**: 
- The computed integer result of the expression

**Functionality**:
- Scans the postfix expression from left to right
- **For digits**: Converts character to integer and pushes onto value stack
- **For operators**: 
  - Pops two operands from the stack
  - Applies the operator using `operator_eval()`
  - Pushes the result back onto the stack
- Returns the final value remaining on the stack

## Main Method Organization

The `main()` function is organized as follows:

1. **Variable Declaration**: Declares two character arrays `infix[MAX]` and `postfix[MAX]` to store the input and converted expressions

2. **User Input**: Prompts the user to enter an infix expression and reads it using `scanf()`

3. **Display Input**: Prints the given infix expression for confirmation

4. **Conversion**: Calls `infix_to_postfix()` to convert the infix expression to postfix notation and display it

5. **Evaluation**: Calls `postfix_eval()` to compute the result of the postfix expression

6. **Display Result**: Prints the final computed result

7. **Program Termination**: Returns 0 to indicate successful execution

The main function orchestrates the entire process from input to output, delegating conversion and evaluation to specialized functions.


## Sample Output
<img width="426" height="115" alt="Screenshot 2026-02-10 at 8 24 22 PM" src="https://github.com/user-attachments/assets/450442b7-c2bd-4185-8b73-27ef1b18f87f" />
