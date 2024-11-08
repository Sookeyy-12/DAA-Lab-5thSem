#include <bits/stdc++.h>
using namespace std;

void solve(vector<pair<int, pair<int, int>>> &prof_job_dead, int n)
{
    sort(prof_job_dead.rbegin(), prof_job_dead.rend());
    vector<int> result(n, -1);
    vector<bool> slot(n, false);
    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, prof_job_dead[i].second.second) - 1; j >= 0; j--)
        {
            // Free slot found
            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << prof_job_dead[result[i]].second.first << " ";
            if (i < n - 1 && slot[i + 1]) {
                cout << "->";
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    // job id, profit, deadline
    vector<pair<int, pair<int, int>>> prof_job_dead(n);
    for (int i = 0; i < n; i++)
    {
        int job;
        cin >> job;
        int prof;
        int dead;
        cin >> dead;
        cin >> prof;
        prof_job_dead[i] = {prof, {job, dead}};
    }
    solve(prof_job_dead, n);
}