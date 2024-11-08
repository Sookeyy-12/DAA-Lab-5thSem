#include <bits/stdc++.h>
using namespace std;

void solve(int n, int w, vector<int>& profit, vector<int>& weight) {
    vector<int> dp(w+1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = w; j >= weight[i-1]; j--) {
            if (weight[i-1] <= j) {
                dp[j] = max(dp[j], dp[j-weight[i-1]] + profit[i-1]);
            }
        }
    }
    cout << "Max Profit: " << dp[w] << endl;
}

int main() {
    int n; cin >> n;
    int w; cin >> w;
    vector<int> profit(n), weight(n);
    for (int i = 0; i < n; i++) cin >> profit[i];
    for (int i = 0; i < n; i++) cin >> weight[i];
    solve(n, w, profit, weight);
}