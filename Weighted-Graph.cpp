#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

class WeightedGraph {
private:
    vector<vector<pair<int, int>>> adj;
    int V;

public:
    WeightedGraph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int v, int w, int weight) {
        adj[v].push_back(make_pair(w, weight));
    }

    void BFS(int start) {
        queue<pair<int, int>> queue;
        vector<bool> visited (V, false);
        queue.push({start, 0});
        visited[start] = true;
        while(!queue.empty()){
            int v = queue.front().first;
            int weight = queue.front().second;
            cout << "Vertex: " << v << " | Weight: " << weight << endl;
            queue.pop();
            for(auto adjVertex : adj[v]){
                if(!visited[adjVertex.first]){
                    visited[adjVertex.first] = true;
                    queue.push(adjVertex);
                }
            }
        }
        cout << endl;
    }

    void DFS(int start){
        stack<pair<int, int>> stack;
        vector<bool> visited (V, false);
        stack.push({start, 0});
        visited[start] = true;
        while(!stack.empty()){
            int v = stack.top().first;
            int weight = stack.top().second;
            cout << "Vertex: " << v << " | Weight: " << weight << endl;
            stack.pop();
            for(auto adjVertex : adj[v]){
                if(!visited[adjVertex.first]){
                    visited[adjVertex.first] = true;
                    stack.push(adjVertex);
                }
            }
        }
        cout << endl;
    }

};

int main() {
    WeightedGraph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);
    g.addEdge(4, 5, 10);

    g.BFS(0);
    g.DFS(0);

    return 0;
}
