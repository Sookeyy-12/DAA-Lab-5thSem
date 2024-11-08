#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> createAdj(int n, vector<vector<int>>& sdw) {
    vector<vector<pair<int, int>>> adjList(n);
    for (int i = 0; i < n; i++) {
        int u = sdw[i][0];
        int v = sdw[i][1];
        int w = sdw[i][2];
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    return adjList;
}

void solve(vector<vector<pair<int, int>>>& adjList, int n) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> visited(n, 0);
    pq.push({0, {0, -1}}); // weight, node, parent
    int mstSum = 0;
    vector<pair<int, int>> mst;
    while(!pq.empty()) {
        auto wt_node_parent = pq.top();
        pq.pop();
        int weight = wt_node_parent.first;
        int node = wt_node_parent.second.first;
        int parent = wt_node_parent.second.second;
        if(visited[node]) continue;
        visited[node] = 1;
        mstSum += weight;
        if(node!=0 && parent!=-1) {
            mst.push_back({node, parent});
        }
        for (auto adjNode: adjList[node]) {
            int adjwt = adjNode.second;
            int adjnode = adjNode.first;
            if(!visited[adjnode]) {
                pq.push({adjwt, {adjnode, node}});
            }
        }
    }
    cout << "connections: \n";
    for (auto m: mst) {
        cout << m.first << " " << m.second << endl;
    }
    cout << "MST Sum: " << mstSum << endl;
}

int main() {
    int n; cin >> n;
    vector<vector<int>> sdw(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        int s, d, w; cin >> s >> d >> w;
        sdw[i] = {s, d, w};
    }
    vector<vector<pair<int,int>>> adjList = createAdj(n, sdw);
    solve(adjList, n);
}