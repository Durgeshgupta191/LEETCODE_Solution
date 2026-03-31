#include <iostream>   // For input-output operations
#include <list>       // For using list (adjacency list)
#include<vector>
using namespace std;

class Graph {
    int V;              // Number of vertices in the graph
    list<int>* l;       // Adjacency list (array of lists)

public:
    // Constructor to initialize graph with V vertices
    Graph(int V) {
        this->V = V;            // Assign number of vertices
        l = new list<int>[V];   // Create adjacency list
    }

    // Function to add an edge between vertex v and u
    // This creates an undirected graph
    void addEdge(int v, int u) {
        l[v].push_back(u);      // Add u to v's list
        l[u].push_back(v);      // Add v to u's list
    }

    // Function to print adjacency list representation
    void printList() {
        for (int i = 0; i < V; i++) {
            cout << i << " : "; // Print vertex number
            for (int neigh : l[i]) {
             LC_   cout << neigh << " "; // Print neighbors
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);  // Create graph with 5 vertices (0 to 4)

    // Adding edges 
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    // Print the graph
    g.printList();

    return 0;
}
