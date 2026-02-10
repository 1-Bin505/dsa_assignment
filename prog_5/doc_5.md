# Sorting Algorithms Comparison Program

## Overview
This program implements and compares four different sorting algorithms: Bubble Sort, Selection Sort, Insertion Sort, and Merge Sort. It generates random numbers, allows the user to select a sorting algorithm, sorts the data, and displays performance metrics including the number of comparisons and swaps/assignments performed during sorting.

## Data Structures

### Arrays
- **data[]**: Dynamically sized array to store random integers (maximum 1000 elements)
- **copy[]**: Duplicate array used for sorting without modifying the original data
- **left_arr[] and right_arr[]**: Temporary arrays used during merge operation in Merge Sort

### Global Counters
- **checks**: Long long integer tracking the total number of comparisons made during sorting
- **moves**: Long long integer tracking the total number of swaps or data movements during sorting

These counters are reset at the beginning of each sorting algorithm to accurately measure performance.

## Functions Implemented

### 1. `void exchange(int *x, int *y)`
**Purpose**: Swaps the values of two integers and increments the moves counter.

**Parameters**:
- `x`: Pointer to the first integer
- `y`: Pointer to the second integer

**Functionality**:
- Uses a temporary variable to swap values
- Increments the global `moves` counter
- Used by comparison-based sorting algorithms

### 2. `void bubble_sort(int data[], int size)`
**Purpose**: Sorts the array using the Bubble Sort algorithm.

**Parameters**:
- `data[]`: Array of integers to be sorted
- `size`: Number of elements in the array

**Functionality**:
- Resets `checks` and `moves` counters to zero
- Uses nested loops to compare adjacent elements
- Swaps elements if they are in wrong order
- After each pass, the largest unsorted element "bubbles up" to its correct position
- Outer loop runs n-1 times, inner loop decreases by 1 each iteration
- Time complexity: O(n²) in worst and average cases
- Space complexity: O(1)

### 3. `void selection_sort(int data[], int size)`
**Purpose**: Sorts the array using the Selection Sort algorithm.

**Parameters**:
- `data[]`: Array of integers to be sorted
- `size`: Number of elements in the array

**Functionality**:
- Resets `checks` and `moves` counters to zero
- Divides the array into sorted and unsorted portions
- Finds the smallest element in the unsorted portion
- Swaps it with the first element of the unsorted portion
- Only swaps if the smallest element is not already in position
- Time complexity: O(n²) in all cases
- Space complexity: O(1)
- Fewer swaps compared to Bubble Sort

### 4. `void insertion_sort(int data[], int size)`
**Purpose**: Sorts the array using the Insertion Sort algorithm.

**Parameters**:
- `data[]`: Array of integers to be sorted
- `size`: Number of elements in the array

**Functionality**:
- Resets `checks` and `moves` counters to zero
- Builds the sorted array one element at a time
- Takes each element and inserts it into its correct position in the sorted portion
- Shifts larger elements to the right to make space
- Efficient for small datasets or nearly sorted data
- Time complexity: O(n²) worst case, O(n) best case (already sorted)
- Space complexity: O(1)

### 5. `void combine(int data[], int left, int middle, int right)`
**Purpose**: Merges two sorted subarrays into a single sorted array (helper function for Merge Sort).

**Parameters**:
- `data[]`: Array containing both subarrays
- `left`: Starting index of the first subarray
- `middle`: Ending index of the first subarray
- `right`: Ending index of the second subarray

**Functionality**:
- Creates two temporary arrays for the left and right subarrays
- Copies data into temporary arrays
- Compares elements from both subarrays and merges them in sorted order
- Copies remaining elements from either subarray if one is exhausted
- Increments `checks` for each comparison
- Increments `moves` for each assignment
- Essential component of the divide-and-conquer approach

### 6. `void merge_sort(int data[], int left, int right)`
**Purpose**: Sorts the array using the Merge Sort algorithm (recursive divide-and-conquer approach).

**Parameters**:
- `data[]`: Array of integers to be sorted
- `left`: Starting index of the portion to be sorted
- `right`: Ending index of the portion to be sorted

**Functionality**:
- Recursively divides the array into two halves
- Base case: when `left >= right`, the subarray has 0 or 1 element (already sorted)
- Recursive case: 
  - Calculates middle point
  - Recursively sorts left half
  - Recursively sorts right half
  - Merges the two sorted halves using `combine()`
- Time complexity: O(n log n) in all cases
- Space complexity: O(n) due to temporary arrays
- Most efficient for large datasets

### 7. `void display(int data[], int size)`
**Purpose**: Prints all elements of the array.

**Parameters**:
- `data[]`: Array of integers to be displayed
- `size`: Number of elements in the array

**Functionality**:
- Iterates through the array
- Prints each element followed by a space
- Prints a newline at the end
- Used to display both unsorted and sorted arrays

## Main Method Organization

The `main()` function is organized as follows:

1. **Input Size**:
   - Prompts user to enter the number of integers
   - Validates input (must be between 1 and 1000)
   - Exits with error message if invalid

2. **Generate Random Data**:
   - Seeds the random number generator with current time
   - Creates an array of specified size
   - Fills array with random integers between 1 and 1000

3. **Display Original Data**:
   - Prints the generated random numbers

4. **Algorithm Selection**:
   - Displays menu with 4 sorting algorithm options
   - Reads user's choice

5. **Copy Array**:
   - Creates a duplicate of the original array
   - Ensures original data remains unchanged

6. **Execute Sorting**:
   - Uses switch statement to call the selected sorting algorithm
   - Resets counters before Merge Sort (since it's handled differently)
   - Prints confirmation message

7. **Display Results**:
   - Prints the sorted array
   - Displays total number of comparisons performed
   - Displays total number of swaps/assignments performed

8. **Error Handling**:
   - Returns error code 1 for invalid input or choice
   - Returns 0 on successful completion

The main function provides a complete workflow for comparing sorting algorithm performance, allowing users to see both the sorted output and efficiency metrics for different algorithms on the same dataset.

## Sample Output
<img width="242" height="54" alt="Screenshot 2026-02-10 at 8 33 17 PM" src="https://github.com/user-attachments/assets/ef60539e-b0d0-4ea8-9dd1-12395b76c9c0" />

