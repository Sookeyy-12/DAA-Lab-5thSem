#include <bits/stdc++.h>
using namespace std;

void dijkstras(int V, vector<vector<int>>& s_d_w, int n, int src, int dest) {
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < n; i++) {
        int u = s_d_w[i][0];
        int v = s_d_w[i][1];
        int w = s_d_w[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    // start dijkstras
    vector<int> distance(V, 1e9);
    distance[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // dist. node
    pq.push({0, src});
    while(!pq.empty()) {
        int currdist = pq.top().first;
        int currnode = pq.top().second;
        pq.pop();
        for (auto adjNode_weight: adj[currnode]) {
            int adjNode = adjNode_weight.first;
            int weight = adjNode_weight.second;
            if(currdist + weight < distance[adjNode]) {
                distance[adjNode] = currdist + weight;
                pq.push({distance[adjNode], adjNode});
            }
        }
    }
    cout << "Minimum Distance from " << src << " to " << dest << " is: " << distance[dest] << endl;
}

int main() {
    int V; cin >> V;
    int n; cin >> n;
    vector<vector<int>> src_dest_weight(n, vector<int>(3, 0));
    for(int i = 0; i < n; i++) {
        cin >> src_dest_weight[i][0];
        cin >> src_dest_weight[i][1];
        cin >> src_dest_weight[i][2];
    }
    int src, dest; cin >> src >> dest;
    dijkstras(V, src_dest_weight, n, src, dest);
}