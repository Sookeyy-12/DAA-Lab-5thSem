#include <bits/stdc++.h>
using namespace std;

void solve(int V, int E, vector<vector<int>>& sdw, int src, int dest) {
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++) {
        int u = sdw[i][0];
        int v = sdw[i][1];
        int w = sdw[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    //dijkstras
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});  // dist, node
    vector<int> distance(V, 1e9);
    distance[src] = 0;
    while(!pq.empty()) {
        auto dn = pq.top(); pq.pop();
        int dist = dn.first;
        int node = dn.second;
        for (auto adjNode_wt: adj[node]) {
            int adjNode = adjNode_wt.first;
            int adjwt = adjNode_wt.second;
            if(dist + adjwt < distance[adjNode]) {
                distance[adjNode] = dist + adjwt;
                pq.push({distance[adjNode], adjNode});
            }
        }
    }
    cout << "Minimum Distance from " << src << " to " << dest << " is: " << distance[dest] << endl;
}

int main() {
    int V; cin >> V;
    int E; cin >> E;
    vector<vector<int>> sdw(E);
    for (int i = 0; i < E; i++) {
        int s, d, w; cin >> s >> d >> w;
        sdw[i] = {s, d, w};
    }
    int src, dest; cin >> src >> dest;
    solve(V, E, sdw, src, dest);
}