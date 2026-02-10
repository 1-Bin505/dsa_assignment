# Singly Linked List Program

## Overview
This program implements a singly linked list data structure with operations to insert nodes at the beginning and end of the list, and traverse the list both forward (iteratively) and backward (recursively). The list maintains pointers to both the first and last nodes for efficient insertions.

## Data Structures

### Node Structure
- **Type**: Structure with self-referential pointer
- **Declaration**: 
  ```c
  typedef struct Node {
      int data;
      struct Node* next;
  } Node;
  ```
- **Members**:
  - `data`: Integer value stored in the node
  - `next`: Pointer to the next node in the list
- **Purpose**: Represents individual elements in the linked list

### Global Pointers
- **first**: Pointer to the first node in the list (head pointer)
  - Initialized to `NULL` indicating an empty list
  
- **last**: Pointer to the last node in the list (tail pointer)
  - Initialized to `NULL` indicating an empty list
  - Enables O(1) insertion at the end

## Functions Implemented

### 1. `void initialize()`
**Purpose**: Initializes the linked list to an empty state.

**Parameters**: None

**Functionality**:
- Sets both `first` and `last` pointers to `NULL`
- Prepares the list for subsequent operations
- Should be called before any other list operations

### 2. `int is_empty()`
**Purpose**: Checks whether the linked list is empty.

**Parameters**: None

**Return Value**: 
- Returns 1 (true) if the list is empty
- Returns 0 (false) if the list contains at least one node

**Functionality**:
- Evaluates whether `first` pointer is `NULL`
- Used by other functions to handle edge cases

### 3. `void insert_end(int value)`
**Purpose**: Inserts a new node with the given value at the end of the list.

**Parameters**:
- `value`: The integer data to be stored in the new node

**Functionality**:
- Dynamically allocates memory for a new node using `malloc()`
- Sets the node's data to the given value
- Sets the node's next pointer to `NULL` (as it will be the last node)
- **If list is empty**: Both `first` and `last` point to the new node
- **If list is not empty**: 
  - Links the current last node to the new node
  - Updates `last` to point to the new node
- Time complexity: O(1) due to tail pointer

### 4. `void insert_beginning(int value)`
**Purpose**: Inserts a new node with the given value at the beginning of the list.

**Parameters**:
- `value`: The integer data to be stored in the new node

**Functionality**:
- Dynamically allocates memory for a new node
- Sets the node's data to the given value
- Links the new node to the current first node
- **If list is empty**: Updates `last` to point to the new node
- Updates `first` to point to the new node
- Time complexity: O(1)

### 5. `void display_forward()`
**Purpose**: Traverses and prints the linked list from beginning to end iteratively.

**Parameters**: None

**Functionality**:
- Starts from the `first` node
- Uses a while loop to traverse through all nodes
- Prints each node's data followed by "->" separator
- Prints the last node's data without the arrow
- Displays format: `Regular Traversal is: node1->node2->node3`
- Time complexity: O(n) where n is the number of nodes

### 6. `void display_backward(Node* current)`
**Purpose**: Recursively traverses and prints the linked list in reverse order.

**Parameters**:
- `current`: Pointer to the current node being processed

**Functionality**:
- Uses recursion to achieve reverse traversal without modifying the list structure
- **Base case**: Returns immediately if `current` is `NULL`
- **Recursive case**: 
  - First calls itself with the next node
  - Then prints the current node's data
- Prints "->" separator after each node except the first node
- Displays the list in reverse order
- Time complexity: O(n), Space complexity: O(n) due to recursion stack

## Main Method Organization

The `main()` function is organized as follows:

1. **Initialization**: Calls `initialize()` to set up an empty linked list

2. **Data Insertion**: 
   - Inserts 45 at the end (list: 45)
   - Inserts 53 at the beginning (list: 53->45)
   - Inserts 34 at the end (list: 53->45->34)

3. **Forward Traversal**: Calls `display_forward()` to print the list from beginning to end

4. **Reverse Traversal**: 
   - Prints "Reverse Traversal is: " 
   - Calls `display_backward(first)` to print the list in reverse order

5. **Program Termination**: Implicit return 0 (main function ends)

The main function demonstrates the basic operations of the linked list by creating a list with three nodes and displaying it in both forward and reverse order. The resulting output shows the list as `53->45->34` in forward traversal and `34->45->53` in reverse traversal.


## Sample Output
<img width="262" height="57" alt="Screenshot 2026-02-10 at 8 27 43 PM" src="https://github.com/user-attachments/assets/3bf0a2a2-227c-4374-a3bd-2d88c001f751" />

