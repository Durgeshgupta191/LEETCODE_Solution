#include <iostream>   // For input-output operations
#include <list>       // For adjacency list
#include <vector>     // For visited array
#include <queue>      // For BFS queue
using namespace std;

class Graph {
    int V;              // Number of vertices in the graph
    list<int>* l;       // Adjacency list (array of lists)

public:
    // Constructor to initialize graph with V vertices
    Graph(int V) {
        this->V = V;            // Store number of vertices
        l = new list<int>[V];   // Allocate adjacency list
    }

    // Function to add an undirected edge between v and u
    void addEdge(int v, int u) {
        l[v].push_back(u);      // Add u to v's adjacency list
        l[u].push_back(v);      // Add v to u's adjacency list
    }

    // Breadth First Search (BFS) traversal starting from vertex 0
    void BFS() {
        queue<int> q;                 // Queue for BFS
        vector<bool> vis(V, false);   // Visited array

        q.push(0);        // Start BFS from vertex 0
        vis[0] = true;    // Mark vertex 0 as visited

        while (!q.empty()) {
            int u = q.front(); // Get front vertex
            q.pop();           // Remove from queue
            cout << u << " ";  // Print vertex

            // Visit all adjacent vertices
            for (int v : l[u]) {
                if (!vis[v]) {
                    vis[v] = true; // Mark as visited
                    q.push(v);     // Push into queue
                }
            }
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Graph() {
        delete[] l;
    }
};   //  IMPORTANT: class ends here

int main() {
    Graph g(5);  // Create graph with 5 vertices (0 to 4)

    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    // Perform BFS traversal
    g.BFS();

    return 0;
}
