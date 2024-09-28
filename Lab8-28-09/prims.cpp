#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> create_adjlist(vector<vector<int>>& src_dest_weight, int n) {
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n; i++) {
        vector<int> sdw = src_dest_weight[i];
        int u = sdw[0];
        int v = sdw[1];
        int w = sdw[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    return adj;
}

void mst_prims(vector<vector<pair<int, int>>>& adj, int n) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
    vector<int> visited(n, 0);
    minHeap.push({0, {0, -1}});
    int mstSum = 0;
    vector<pair<int,int>> mst;
    while(!minHeap.empty()) {
        auto wt_node_parent = minHeap.top();
        minHeap.pop();
        int weight = wt_node_parent.first;
        int node = wt_node_parent.second.first;
        int parent = wt_node_parent.second.second;
        if(visited[node]) continue;
        visited[node] = 1;
        mstSum+=weight;
        if(node!=0 && parent!=-1) {
            mst.push_back({node, parent});
        }
        for (auto adjNode: adj[node]) {
            int adjwt = adjNode.second;
            int adjnode = adjNode.first;
            if(!visited[adjnode]) {
                minHeap.push({adjwt, {adjnode, node}});
            }
        }
    }
    cout << "Connections: " << endl;
    for (auto m: mst) {
        cout << m.first << " " << m.second << endl;
    }
    cout << "MST Sum: ";
    cout << mstSum << endl;
}

int main() {
    int n; cin >> n;
    int E; cin >> E;
    vector<vector<int>> src_dest_weight(E, vector<int>(3, 0));
    for (int i = 0; i < E; i++) {
        cin >> src_dest_weight[i][0];
        cin >> src_dest_weight[i][1];
        cin >> src_dest_weight[i][2];
    }
    vector<vector<pair<int, int>>> adj = create_adjlist(src_dest_weight, n);
    mst_prims(adj, n);
}