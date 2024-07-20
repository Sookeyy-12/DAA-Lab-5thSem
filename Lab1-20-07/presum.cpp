#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& array) {
    vector<int> preSum(array.size(), 0);
    preSum[0] = array[0];
    for (int i = 1; i < array.size(); i++) {
        preSum[i] = preSum[i-1] + array[i];
    }
    for (int p: preSum) {
        cout << p << " ";
    }
    cout << endl;
}

int main() {
    vector<int> array = {2, 5, 9, 12, 15};
    solve(array);
    return 0;
}