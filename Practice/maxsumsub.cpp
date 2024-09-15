#include <bits/stdc++.h>
using namespace std;

int maxsum(vector<int> arr, int n) {
    int maxSum = 0;
    for (int i = 0; i < n; i++) {
        int tmpSum = 0;
        for (int j = i; j < n; j++) {
            tmpSum += arr[j];
            maxSum = max(maxSum, tmpSum);
        }
    }
    return maxSum;
}

int main() {
    vector<int> arr = {2, -6, -1, 3, -1, 2, -2};
    cout << maxsum(arr, arr.size()) << endl;
}