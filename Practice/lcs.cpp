#include <bits/stdc++.h>
using namespace std;

void solve(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            if(s1[i-1]==s2[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << "length of lcs: " << dp[n][m] << endl;
    string lcs = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs = s1[i-1] + lcs;
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << "lcs: " << lcs;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    solve(s1, s2);
}