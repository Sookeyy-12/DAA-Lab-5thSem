#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<pair<int, pair<int, int>>>& jobs) {
    vector<int> res(n, -1);
    vector<bool> slot(n, false);
    sort(jobs.rbegin(), jobs.rend());
    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].second.second)-1; j>=0; j--) {
            if(!slot[j]) {
                res[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if(res[i]!=-1) {
            cout << jobs[res[i]].second.first << " ";
        }
    }
}

int main() {
    int n; cin >> n;
    vector<pair<int, pair<int, int>>> jobs(n);
    for (int i = 0; i < n; i++) {
        int job, deadline, profit;
        cin >> job >> deadline >> profit;
        jobs[i] = {profit, {job, deadline}};
    }
    solve(n, jobs);
}