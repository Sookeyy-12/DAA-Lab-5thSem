#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& arr) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len < n; len++) {
        for (int i = 0; i < n-len; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for (int k = i+1; k<j; k++) {
                int cost = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    cout << "Minimum mutiplications: " << dp[0][n-1] << endl;
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    solve(n, arr);
}