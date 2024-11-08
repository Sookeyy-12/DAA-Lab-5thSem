#include <bits/stdc++.h>
using namespace std;

vector<int> parent, rankDSU;

void initializeDSU(int n) {
	parent.resize(n, -1);
	rankDSU.resize(n, 1);
}

int find(int i) {
	if (parent[i] == -1)
		return i;
	return parent[i] = find(parent[i]);
}

void unite(int x, int y) {
	int s1 = find(x);
	int s2 = find(y);

	if (s1 != s2) {
		if (rankDSU[s1] < rankDSU[s2]) {
			parent[s1] = s2;
		} else if (rankDSU[s1] > rankDSU[s2]) {
			parent[s2] = s1;
		} else {
			parent[s2] = s1;
			rankDSU[s1] += 1;
		}
	}
}

void addEdge(vector<vector<int>>& edgelist, int x, int y, int w) {
	edgelist.push_back({w, x, y});
}

void kruskals_mst(vector<vector<int>>& edgelist, int V) {
	sort(edgelist.begin(), edgelist.end());
	initializeDSU(V);
	int ans = 0;
	cout << "Following are the edges in the constructed MST" << endl;
	for (auto edge : edgelist) {
		int w = edge[0];
		int x = edge[1];
		int y = edge[2];
		if (find(x) != find(y)) {
			unite(x, y);
			ans += w;
			cout << x << " -- " << y << " == " << w << endl;
		}
	}
	cout << "Minimum Cost Spanning Tree: " << ans;
}

int main() {
	int V = 4;
	vector<vector<int>> edgelist;
	addEdge(edgelist, 0, 1, 10);
	addEdge(edgelist, 1, 3, 15);
	addEdge(edgelist, 2, 3, 4);
	addEdge(edgelist, 2, 0, 6);
	addEdge(edgelist, 0, 3, 5);
	kruskals_mst(edgelist, V);

	return 0;
}
