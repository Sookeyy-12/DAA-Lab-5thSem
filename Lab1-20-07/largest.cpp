#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& array) {
    // cout << *max_element(array.begin(), array.end()) << endl;
    int largest = INT_MIN;
    for (int a: array) {
        if (a > largest) {
            largest = a;
        }
    }
    cout  <<  "Largest element is " << largest << endl;
}

int main() {
    vector<int> array = {5, 2, 1, 67, 12, 22, 15};
    solve(array);
    return 0;
}