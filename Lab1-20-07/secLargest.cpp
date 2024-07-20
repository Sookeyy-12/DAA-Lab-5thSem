#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& array) {
    int fs = array[0];
    int ss = array[0];
    int fl = array[0];
    int sl = array[0];
    for (auto a: array) {
        if(a > fl) {
            fl = a;
        } else if (a < fl && a > sl) {
            sl = a;
        }
        if(a < fs) {
            fs = a;
        } else if (a > fs && a < ss) {
            ss = a;
        }
    }
    cout << "Second Largest element: " << sl << endl;
    cout << "Second Smallest element: " << ss << endl;
}

int main() {
    vector<int> array = {12, 2, 4, 13, 19, 17, 8};
    solve(array);
    return 0;
}