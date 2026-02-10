# Sorting Comparison Program (Bubble, Selection, Insertion, and Merge Sort)

## Overview
This program implements and compares four classic sorting algorithms: **Bubble Sort**, **Selection Sort**, **Insertion Sort**, and **Merge Sort**. It generates a set of random integers and allows the user to select an algorithm to sort them. The program uniquely tracks the efficiency of each algorithm by counting the total number of comparisons (checks) and data movements (swaps/assignments).



## Data Structures
### Data Array
* **Type:** Integer array
* **Declaration:** `int data[total]` and `int copy[total]`
* **Size:** Up to 1000 elements (defined by `MAX`)
* **Purpose:** `data[]` stores the original randomly generated numbers, while `copy[]` is used for the actual sorting process to preserve the original input.

### Global Counters
* **Type:** Long long integers
* **Variables:** `checks` (comparisons) and `moves` (swaps or assignments)
* **Purpose:** Used to measure and report the performance metrics of the selected sorting algorithm.

---

## Functions Implemented

### 1. void bubble_sort(int data[], int size)
* **Purpose:** Sorts the array using the bubble sort technique.
* **Logic:** Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. 
* **Complexity:** $O(n^2)$

### 2. void selection_sort(int data[], int size)
* **Purpose:** Sorts the array by repeatedly finding the minimum element from the unsorted part.
* **Logic:** Divides the array into a sorted and unsorted region. It finds the smallest element in the unsorted region and swaps it with the first element of that region.
* **Complexity:** $O(n^2)$

### 3. void insertion_sort(int data[], int size)
* **Purpose:** Sorts by building the final sorted array one item at a time.
* **Logic:** Takes one element at a time and "inserts" it into its correct position among the previously sorted elements by shifting larger elements to the right.
* **Complexity:** $O(n^2)$

### 4. void merge_sort(int data[], int left, int right)
* **Purpose:** A recursive divide-and-conquer sorting algorithm.
* **Logic:** Splits the array into two halves, recursively sorts them, and then merges the halves using the `combine()` helper function.
* **Complexity:** $O(n \log n)$



### 5. Helper Functions
* **void exchange(int *x, int *y):** Swaps two integers and increments the `moves` counter.
* **void combine(int data[], int left, int middle, int right):** Merges two sorted sub-arrays into a single sorted sub-array.
* **void display(int data[], int size):** Prints the elements of the array.

---

## Main Method Organization
The `main()` function is organized as follows:

1.  **Input & Initialization:**
    * Requests the number of elements from the user (with validation against `MAX`).
    * Initializes the random number generator using `srand(time(0))`.
    * Fills the array with random values between 1 and 1000 and displays them.
2.  **Algorithm Selection:**
    * Displays a menu for the four sorting algorithms.
    * Creates a copy of the original data to ensure the sorting doesn't affect the master list.
3.  **Execution & Monitoring:**
    * Executes the chosen algorithm via a `switch` statement.
    * Resets and tracks `checks` and `moves` during execution.
4.  **Reporting:**
    * Displays the sorted array.
    * Outputs the total number of comparisons and swaps/assignments performed.

---

## Sample Output

