//Purpose: Implementation of Dijkstra's algorithm which finds the shortest
//path from a start node to every other node in a weighted graph. 
//Time complexity: O(n^2)
#include <iostream>
#include <limits>
using namespace std;

#define MAXV 1000

class EdgeNode{
    public:
        int key;
        int weight;
        EdgeNode *next;
        EdgeNode(int, int);
};

EdgeNode::EdgeNode(int key, int weight){
    this->key = key;
    this->weight = weight;
    this->next = NULL;
}

class Graph{
    bool directed;
    public:
        EdgeNode *edges[MAXV + 1];
        Graph(bool);
        ~Graph();
        void insert_edge(int, int, int, bool);
        void print();
};

Graph::Graph(bool directed){
    this->directed = directed;
    for(int i = 1; i < (MAXV + 1); i ++){
        this->edges[i] = NULL;
    }
}

Graph::~Graph(){
    //to do
}

void Graph::insert_edge(int x, int y, int weight, bool directed){
    if(x > 0 && x < (MAXV + 1) && y > 0 && y < (MAXV + 1)){
        EdgeNode *edge = new EdgeNode(y, weight);
        edge->next = this->edges[x];
        this->edges[x] = edge;
        if(!directed){
            insert_edge(y, x, weight, true);
        }
    }
}

void Graph::print(){
    for(int v = 1; v < (MAXV + 1); v ++){
        if(this->edges[v] != NULL){
            cout << "Vertex " << v << " has neighbors: " << endl;
            EdgeNode *curr = this->edges[v];
            while(curr != NULL){
                cout << curr->key << endl;
                curr = curr->next;
            }
        }
    }
}

void init_vars(bool discovered[], int distance[], int parent[]){
    for(int i = 1; i < (MAXV + 1); i ++){
        discovered[i] = false;
        distance[i] = std::numeric_limits<int>::max();
        parent[i] = -1;
    }
}

void dijkstra_shortest_path(Graph *g, int parent[], int distance[], int start){

    bool discovered[MAXV + 1];
    EdgeNode *curr;
    int v_curr;
    int v_neighbor;
    int weight;
    int smallest_dist;

    init_vars(discovered, distance, parent);

    distance[start] = 0;
    v_curr = start;

    while(discovered[v_curr] == false){

        discovered[v_curr] = true;
        curr = g->edges[v_curr];

        while(curr != NULL){

            v_neighbor = curr->key;
            weight = curr->weight;

            if((distance[v_curr] + weight) < distance[v_neighbor]){
                distance[v_neighbor] = distance[v_curr] + weight;
                parent[v_neighbor] = v_curr;
            }
            curr = curr->next;
        }

        //set the next current vertex to the vertex with the smallest distance
        smallest_dist = std::numeric_limits<int>::max();
        for(int i = 1; i < (MAXV + 1); i ++){
            if(!discovered[i] && (distance[i] < smallest_dist)){
                v_curr = i;
                smallest_dist = distance[i];
            }
        }
    }
}

void print_shortest_path(int v, int parent[]){
    if(v > 0 && v < (MAXV + 1) && parent[v] != -1){
        cout << parent[v] << " ";
        print_shortest_path(parent[v], parent);
    }
}

void print_distances(int start, int distance[]){
    for(int i = 1; i < (MAXV + 1); i ++){
        if(distance[i] != std::numeric_limits<int>::max()){
            cout << "Shortest distance from " << start << " to " << i << " is: " << distance[i] << endl;
        }
    }
}

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
    //print shortest path from vertex 1 to 5
    print_shortest_path(5, parent);
    print_distances(start, distance);

    delete g;
    return 0;
}
