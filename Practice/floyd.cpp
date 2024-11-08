#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<vector<int>>& mat) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(mat[i][j] == -1) {
                mat[i][j] = 1e9;
            }
        }
    }
    for (int via = 0; via < n; via++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = min(
                    mat[i][j],
                    mat[i][via]+mat[via][j]
                );
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(mat[i][j]==1e9) {
                cout << -1 << " ";
            } else {
                cout << mat[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n; cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    solve(n, mat);
}