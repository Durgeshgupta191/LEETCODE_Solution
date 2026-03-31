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

    // Depth First Search (BFS) traversal starting from vertex 0

    void helperDFS(int u, vector<bool>&vis){
        cout<<u<<" ";
        vis[u]=true;

        for(int v : l[u]){
            if(!vis[v]){
                helperDFS(v,vis);
            }
        }
    }
    void DFS(){
        int src =0;
        vector<bool>vis(V,false);

        helperDFS(src,vis);
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
    g.DFS();

    return 0;
}
