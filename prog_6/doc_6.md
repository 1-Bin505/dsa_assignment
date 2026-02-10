# Heap Construction Program (Max-Heap and Min-Heap)

## Overview
This program implements two fundamental heap construction algorithms: **Max-Heap** and **Min-Heap**. It allows a user to input a set of integers, stores them in an array-based binary tree, and demonstrates the transformation of that data into both heap types using the "heapify" (sift-down) method.

## Data Structures
### Heap Array
* **Type:** Integer array
* **Declaration:** `int data[MAX]`
* **Size:** 70 elements maximum (defined by `MAX`)
* **Purpose:** Acts as a complete binary tree where elements are stored in level-order.
* **Representation:** * For an element at index `i`:
        * **Left Child:** `2*i + 1`
        * **Right Child:** `2*i + 2`
        * **Parent:** `(i-1) / 2`

### Size Variable
* **Type:** Integer
* **Declaration:** `int size`
* **Purpose:** Stores the current number of elements provided by the user to define the boundary of the heap within the array.

---

## Functions Implemented

### 1. void adjust_max(int data[], int size, int index)
* **Purpose:** Maintains the Max-Heap property (Parent $\ge$ Children) for a subtree rooted at `index`.
* **Functionality:** * Compares the node at `index` with its left and right children.
    * Identifies the `bigger` of the three nodes.
    * If a child is larger than the parent, they are swapped.
    * **Recursion:** If a swap occurs, the function recursively calls itself on the affected sub-tree to ensure the property is maintained all the way down.

### 2. void adjust_min(int data[], int size, int index)
* **Purpose:** Maintains the Min-Heap property (Parent $\le$ Children) for a subtree rooted at `index`.
* **Functionality:** * Compares the node at `index` with its children to find the `smaller` node.
    * If a child is smaller than the parent, they are swapped.
    * **Recursion:** Recursively calls itself on the child's index to fix any violations caused by the swap.

### 3. void create_max_heap(int data[], int size)
* **Purpose:** Transforms an unordered array into a valid Max-Heap.
* **Functionality:** * Starts from the last non-leaf node (calculated as `size/2 - 1`).
    * Iterates backwards to the root (index 0).
    * Calls `adjust_max` at each step to "heapify" the array.

### 4. void create_min_heap(int data[], int size)
* **Purpose:** Transforms an unordered array into a valid Min-Heap.
* **Functionality:** * Iterates from the last non-leaf node down to index 0.
    * Calls `adjust_min` at each step to restructure the array.

### 5. void display(int data[], int size)
* **Purpose:** Utility function to print the current state of the array.
* **Functionality:** Iterates from `0` to `size - 1` and prints each element separated by a space.

---

## Main Method Organization
The `main()` function is organized as follows:

1.  **Input Acquisition:**
    * Prompts the user for the number of elements.
    * Reads the integers into the `data` array using a `for` loop.
2.  **Max-Heap Construction:**
    * Calls `create_max_heap()` to organize the input data.
    * Prints the label "Max Heap: " followed by the array elements.
3.  **Min-Heap Construction:**
    * Calls `create_min_heap()` on the same data set.
    * Prints the label "Min Heap: " followed by the newly organized array elements.
4.  **Program Termination:**
    * Returns 0 to indicate successful execution.

---

## Sample Output
<img width="309" height="109" alt="Screenshot 2026-02-10 at 8 38 03 PM" src="https://github.com/user-attachments/assets/38b86b45-f395-4547-94f1-89c08bbff58e" />
<img width="369" height="103" alt="Screenshot 2026-02-10 at 8 38 09 PM" src="https://github.com/user-attachments/assets/ee2f0ed6-80a0-4290-b1e8-7e2acde82267" />


