#include <iostream>
#include <queue>
const int INF = 2000000;

using namespace std;

struct cmp{
    bool operator()(pair<int, pair<int, int>> t, pair<int, pair<int, int>> u){
        return t.second.second > u.second.second;
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ** graph;
    bool ** visited;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, cmp> pq;
    int V, E, K;
    int f, t, w;
    cin >> V >> E;
    graph = new int*[V];
    visited = new bool*[V];
    for (int i = 0; i < V; ++i) {
        graph[i] = new int[V];
        visited[i] = new bool[V];
        for (int j = 0; j < V; ++j) {
            graph[i][j] = INF;
            visited[i][j] = false;
        }
    }
    cin >> K;
    --K;
    graph[K][K] = 0;
    for (int i = 0; i < E; ++i) {
        cin >> f >> t >> w;
        graph[f-1][t-1] = w;
    }
    pq.push(make_pair(K, make_pair(K, 0)));
    int src_vertex, dst_vertex, weight_edge;
    pair<int, pair<int, int>> p;
    while (!pq.empty()) {
        p = pq.top();
        pq.pop();
        src_vertex = p.first;
        dst_vertex = p.second.first;
        weight_edge = p.second.second;
        visited[src_vertex][dst_vertex] = true;
        if (graph[src_vertex][src_vertex] + weight_edge < graph[dst_vertex][dst_vertex]) {
            graph[dst_vertex][dst_vertex] = graph[src_vertex][src_vertex] + weight_edge;
            // cout << "Update graph[" << dst_vertex << "][" << dst_vertex << "] = " << graph[dst_vertex][dst_vertex] << "\n";
        }
        for (int i = 0; i < V; ++i) {
            if (i == dst_vertex) continue;
            if (!visited[dst_vertex][i]) {
                pq.push(make_pair(dst_vertex, make_pair(i, graph[dst_vertex][i])));
            }
        }
    }
    for (int i = 0; i < V; ++i) {
        if (graph[i][i] >= INF) {
            cout << "INF" << "\n";
        } else {
            cout << graph[i][i] << '\n';
        } 
    }
    return 0;
}