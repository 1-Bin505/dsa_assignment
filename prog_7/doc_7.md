# Shortest Path Program (Dijkstra's Algorithm)

## Overview
This program implements **Dijkstra's Algorithm** to find the shortest path from a single source node to all other nodes in a weighted graph. The graph is represented using an adjacency matrix where weights represent the "cost" or distance between nodes. The program calculates the minimum distance and traces the specific path taken to reach each destination.



[Image of Dijkstra's algorithm flowchart]


## Data Structures
### Adjacency Matrix
* **Type:** 2D integer array
* **Declaration:** `int matrix[SIZE][SIZE]`
* **Size:** 50×50 maximum (defined by `SIZE`)
* **Purpose:** Stores the weights of edges between nodes.
* **Representation:** `matrix[i][j]` contains the weight of the edge from node $i$ to node $j$. A value of `INF` (Infinity) indicates no direct connection exists.

### Distance Array
* **Type:** Integer array
* **Declaration:** `int distance[SIZE]`
* **Purpose:** Tracks the shortest known distance from the source node to every other node during the execution of the algorithm. Initially set to `INF` for all nodes except the source.

### Previous Node Array
* **Type:** Integer array
* **Declaration:** `int previous[SIZE]`
* **Purpose:** Stores the "predecessor" of each node in the shortest path. This allows the program to backtrack from a destination node to the source to reconstruct the full path.

### Done (Visited) Array
* **Type:** Boolean array
* **Declaration:** `bool done[SIZE]`
* **Purpose:** Keeps track of nodes that have been "finalized" (the shortest path to that node has been found and processed).

---

## Functions Implemented

### 1. int find_minimum(int distance[], bool done[], int total)
* **Purpose:** Finds the unvisited node with the smallest known distance.
* **Functionality:** * Iterates through all nodes.
    * Checks if `done[i]` is false and `distance[i]` is the minimum found so far.
    * Returns the index of the node to be processed next.

### 2. void show_path(int previous[], int node)
* **Purpose:** Recursively/iteratively reconstructs and prints the path from the source to a specific node.
* **Functionality:** * Uses a local array `route[]` to store nodes while backtracking through the `previous[]` array.
    * Prints the nodes in reverse order (from source to destination) using arrows (`->`) for visualization.

### 3. void shortest_path(int matrix[SIZE][SIZE], int total, int start)
* **Purpose:** The core logic of Dijkstra's algorithm.
* **Functionality:** * **Initialization:** Sets all distances to `INF`, all previous nodes to `-1`, and all `done` flags to `false`. Sets the distance of the `start` node to 0.
    * **Relaxation:** Repeatedly selects the minimum distance node, marks it as `done`, and updates the distances of its unvisited neighbors if a shorter path is found through the current node.
    * **Reporting:** Prints a formatted table showing the Node, the total Distance, and the full Path string.

---

## Main Method Organization
The `main()` function is organized as follows:

1.  **Graph Definition:**
    * Defines a graph with **6 nodes**.
    * Initializes a hard-coded adjacency matrix representing a weighted undirected graph.
    * Uses `INF` to represent non-existent edges.
2.  **Algorithm Activation:**
    * Sets the source node (`start = 0`).
    * Calls `shortest_path()` to perform the calculations and display the results.
3.  **Program Termination:**
    * Returns 0 upon successful completion.

---

## Sample Output
![Uploading Screenshot 2026-02-10 at 8.41.37 PM.png…]()

