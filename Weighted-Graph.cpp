#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

class WeightedGraph{
private:
    vector<vector<pair<int, int>>> adj;
    int V;

public:
    WeightedGraph(int vertices) : V(vertices), adj(vertices) {};

    void addEdge(int v, int w, int weight) {
        adj[v].push_back(make_pair(w, weight));
    }

    
};