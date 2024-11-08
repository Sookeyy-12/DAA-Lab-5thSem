#include <bits/stdc++.h>
using namespace std;


void floyd(int V, vector<vector<int>>& src_dest_weight, int n) {
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int u = src_dest_weight[i][0];
        int v = src_dest_weight[i][1];
        int w = src_dest_weight[i][2];
        dist[u][v] = w;
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "The following matrix shows the shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
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
    floyd(V, src_dest_weight, n);
}