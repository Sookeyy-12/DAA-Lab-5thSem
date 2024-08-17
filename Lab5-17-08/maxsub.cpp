#include <bits/stdc++.h>
using namespace std;

int findMaxSubSum(vector<int>& array) {
    int maxSum = 0;
    int currSum = 0;
    for (auto a: array) {
        currSum+=a;
        if(currSum > maxSum) {
            maxSum = currSum;
        }
        if(currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}

int main() {
    cout << "Enter size of Array: ";
    int n; cin >> n;
    cout << "Enter Elements of the Array:\n";
    vector<int> array(n);
    for (auto& a: array) cin >> a;
    int maxSubarraySum = findMaxSubSum(array);
    cout << "Maximum Subarray Sum is: " << maxSubarraySum << endl;
}