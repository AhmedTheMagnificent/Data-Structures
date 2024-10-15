#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph{
private:
    vector<vector<int>> adj;
    int V;

public:
    Graph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int start) {
        queue<int> queue;
        vector<bool> visited(V, false);
        queue.push(start);
        visited[start] = true;
        while (!queue.empty()) {
            int v = queue.front();
            cout << v << " ";
            queue.pop();
            for (auto adjVertex : adj[v]) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.push(adjVertex);
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) {
        stack<int> stack;
        vector<bool> visited(V, false);
        stack.push(start);
        visited[start] = true;
        while (!stack.empty()) {
            int v = stack.top();
            cout << v << " ";
            stack.pop();
            for (auto adjVertex : adj[v]) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    stack.push(adjVertex);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);

    // Adding edges to the graph
    g.addEdge(5, 3);
    g.addEdge(5, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 1);
    g.addEdge(2, 1);

    // Performing BFS starting from vertex 5
    cout << "BFS starting from vertex 5: ";
    g.BFS(5);

    // Performing DFS starting from vertex 5
    cout << "DFS starting from vertex 5: ";
    g.DFS(5);

    return 0;
}


/*
    A graph is a collection of nodes (or vertices) and edges connecting some (possibly empty) pairs of nodes.
    Graphs can be directed or undirected, and they can also be weighted or unweighted.

    Graph traversal refers to the process of visiting all the nodes in a graph.
    The two most common graph traversal algorithms are:

    1. Breadth-First Search (BFS):
        - BFS explores the graph level by level.
        - It starts at a given node and explores all its neighboring nodes at the present depth before moving on to nodes at the next depth level.
        - BFS is implemented using a queue.
    
    2. Depth-First Search (DFS):
        - DFS explores the graph by going as deep as possible along each branch before backtracking.
        - It starts at a given node and explores each branch before moving to the next branch.
        - DFS is implemented using a stack (or recursively using the call stack).
*/

