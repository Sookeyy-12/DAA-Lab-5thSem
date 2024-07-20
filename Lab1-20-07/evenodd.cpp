#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& array) {
    int l = 0, r = array.size()-1;
    while(l<r) {
        while(array[l]%2==0) l++;
        while(array[r]%2!=0) r--;
        if(l>=r) break;
        swap(array[l], array[r]);
    }
    cout << "The modified array is\n";
    for (auto a: array) {
        cout << a << " ";
    }
    cout << endl;
}

int main() {
    vector<int> array = {5, 1, 2, 4, 12, 19, 30};
    solve(array);
    return 0;
}