# Dijkstra's Shortest Path Algorithm Documentation

## Overview

This C++ program implements Dijkstra's algorithm, which finds the shortest path from a starting node to all other nodes in a weighted graph with non-negative weights. The time complexity of this implementation is \( O(n^2) \), where \( n \) is the number of vertices in the graph.

## Code Structure

### 1. **EdgeNode Class**

#### Purpose
Represents an edge in the graph with a key (destination vertex) and a weight.

#### Members
- `int key`: Destination vertex.
- `int weight`: Weight of the edge.
- `EdgeNode *next`: Pointer to the next edge in the adjacency list.

#### Constructor
```cpp
EdgeNode(int key, int weight);
```
Initializes an edge with a destination vertex and weight.

### 2. **Graph Class**

#### Purpose
Represents the graph using an adjacency list.

#### Members
- `bool directed`: Indicates if the graph is directed or undirected.
- `EdgeNode *edges[MAXV + 1]`: Array of pointers to adjacency lists for each vertex.

#### Constructor
```cpp
Graph(bool directed);
```
Initializes the graph and sets the directed property. Initializes all adjacency lists to `NULL`.

#### Destructor
```cpp
~Graph();
```
Currently not implemented. Should deallocate memory used by edges.

#### Methods

- `void insert_edge(int x, int y, int weight, bool directed);`
  - **Purpose**: Inserts an edge between vertices `x` and `y` with the given weight. If the graph is undirected, it adds the edge in both directions.
  - **Parameters**:
    - `x`: Source vertex.
    - `y`: Destination vertex.
    - `weight`: Weight of the edge.
    - `directed`: Boolean indicating if the graph is directed.

- `void print();`
  - **Purpose**: Prints the adjacency list of each vertex.

### 3. **Helper Functions**

#### `void init_vars(bool discovered[], int distance[], int parent[]);`
- **Purpose**: Initializes arrays used by the Dijkstra algorithm.
- **Parameters**:
  - `discovered[]`: Boolean array to mark discovered vertices.
  - `distance[]`: Array to store the shortest distance from the start vertex.
  - `parent[]`: Array to store the parent of each vertex in the shortest path tree.

#### `void dijkstra_shortest_path(Graph *g, int parent[], int distance[], int start);`
- **Purpose**: Computes the shortest path from the `start` vertex to all other vertices using Dijkstra's algorithm.
- **Parameters**:
  - `g`: Pointer to the `Graph` object.
  - `parent[]`: Array to store the parent of each vertex in the shortest path tree.
  - `distance[]`: Array to store the shortest distance from the `start` vertex.
  - `start`: Starting vertex for the shortest path calculation.

#### `void print_shortest_path(int v, int parent[]);`
- **Purpose**: Recursively prints the shortest path from the start vertex to vertex `v` using the `parent[]` array.
- **Parameters**:
  - `v`: The vertex for which the path is to be printed.
  - `parent[]`: Array storing the parent of each vertex.

#### `void print_distances(int start, int distance[]);`
- **Purpose**: Prints the shortest distance from the `start` vertex to all other vertices.
- **Parameters**:
  - `start`: The starting vertex.
  - `distance[]`: Array storing the shortest distance from the `start` vertex.

### 4. **Main Function**

#### Purpose
Sets up a graph, inserts edges, computes shortest paths using Dijkstra's algorithm, and prints the shortest path and distances.

#### Code
```cpp
int main(){
    Graph *g = new Graph(false);
    int parent[MAXV + 1];
    int distance[MAXV + 1];
    int start = 1;

    g->insert_edge(1, 2, 4, false);
    g->insert_edge(1, 3, 1, false);
    g->insert_edge(3, 2, 1, false);
    g->insert_edge(3, 4, 5, false);
    g->insert_edge(2, 4, 3, false);
    g->insert_edge(2, 5, 1, false);
    g->insert_edge(4, 5, 2, false);

    dijkstra_shortest_path(g, parent, distance, start);
    print_shortest_path(5, parent);
    print_distances(start, distance);

    delete g;
    return 0;
}
```
- **Purpose**: Demonstrates the functionality of the graph and Dijkstra's algorithm. Initializes the graph, inserts edges, computes the shortest paths from vertex 1, prints the shortest path to vertex 5, and displays all distances.