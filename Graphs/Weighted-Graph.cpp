#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <limits>

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

    vector<int> Dijkstra(int source){
        const int INF = numeric_limits<int>::max();
        vector<int> distances(V, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
        queue.push({0, source});
        distances[source] = 0;
        while(!queue.empty()){
            int currentDistance = queue.top().first;
            int u = queue.top().second;
            queue.pop();
            if(currentDistance > distances[u]) continue;
            
            for(auto &neightbours : adj[u]){
                int v = neightbours.first;
                int w = neightbours.second;
                
                if(distances[v] > distances[u] + w){
                    distances[v] = distances[u] + w;
                    queue.push({distances[v], v});
                }
            }
        }
        return distances;
    }

    void BFS(int source) {
        queue<pair<int, int>> queue;
        vector<bool> visited (V, false);
        queue.push({source, 0});
        visited[source] = true;
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

    void DFS(int source){
        stack<pair<int, int>> stack;
        vector<bool> visited (V, false);
        stack.push({source, 0});
        visited[source] = true;
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
    vector<int> distances = g.Dijkstra(0);
    for(int i = 0; i < distances.size(); i++){
        if(distances[i] == numeric_limits<int>::max()){
            cout << "Vertex " << i << " is unreachable." << endl;
        }
        else{
            cout << "Vertex" << i << " : " << distances[i] << endl;
        }
    }
    return 0;
}
