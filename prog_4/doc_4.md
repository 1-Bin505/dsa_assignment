# Doubly Linked List Implementation

## Overview
This program implements a **Doubly Linked List (DLL)**, a linear data structure where each node contains a data field and two pointers: one pointing to the next node and one pointing to the previous node. This implementation allows for efficient bidirectional traversal and provides functions for dynamic node insertion and deletion.



## Data Structures
### Node Structure
* **Type:** Custom `struct` (Typedef as `Node`)
* **Components:**
    * `int data`: Stores the integer value of the node.
    * `struct Node* next`: Pointer to the succeeding node in the sequence.
    * `struct Node* prev`: Pointer to the preceding node in the sequence.
* **Purpose:** Forms the building blocks of the list, allowing links in both directions.

### Global Pointers
* **Node* start:** A pointer that always tracks the first node (head) of the list.
* **Node* end:** A pointer that always tracks the last node (tail) of the list.
* **Purpose:** Provides $O(1)$ access to both ends of the list for efficient insertions.

---

## Functions Implemented

### 1. void initialize_list()
* **Purpose:** Prepares the list for use by setting global pointers to `NULL`.

### 2. void top_node(int value)
* **Purpose:** Inserts a new node at the beginning (head) of the list.
* **Logic:** Creates a node where the `next` pointer points to the current `start`. It updates the old start's `prev` pointer to the new node.

### 3. void bot_node(int value)
* **Purpose:** Appends a new node to the end (tail) of the list.
* **Logic:** Creates a node where the `prev` pointer points to the current `end`. It updates the old end's `next` pointer to the new node.

### 4. void add_after_value(int target_value, int new_value)
* **Purpose:** Inserts a new node immediately after a specific existing value.
* **Logic:** Traverses the list to find the `target_value`. If found, it adjusts four pointers (new node's `prev`/`next` and the surrounding nodes' `next`/`prev`) to splice the new node into the sequence.



### 5. int remove_node(int target_value)
* **Purpose:** Deletes a node containing the specified value and frees its memory.
* **Logic:** Locates the node, bridges the `next` pointer of the previous node to the `next` node of the current, and vice versa. It handles edge cases where the node to be removed is the `start` or `end`.

### 6. Traversal Functions
* **display_forward():** Iterates from `start` to `end` using `next` pointers.
* **display_reverse():** Iterates from `end` to `start` using `prev` pointers.

---

## Main Method Organization
The `main()` function demonstrates the lifecycle of the Doubly Linked List:

1.  **List Setup:** Initializes pointers and adds nodes to the bottom (`15, 25, 35`) and the top (`8`).
2.  **Visualization:** Displays the list in forward order and then performs a reverse traversal to verify bidirectional links.
3.  **Intermediate Operations:** * Inserts a node with value `30` specifically after the node containing `25`.
    * Removes the node containing `15` from the middle/start of the list.
4.  **Final State:** Displays the forward list after all modifications to confirm structural integrity.
5.  **Termination:** Returns 0, ending the program.

---

## Sample Output
<img width="390" height="121" alt="Screenshot 2026-02-10 at 8 46 19 PM" src="https://github.com/user-attachments/assets/afb9b053-252b-4a70-907a-0009c1db6eaf" />

