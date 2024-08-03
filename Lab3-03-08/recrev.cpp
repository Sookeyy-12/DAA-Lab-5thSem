#include <bits/stdc++.h>
using namespace std;

void recrev(vector<int>& array, int l, int r) {
    if(r<=l) return;
    swap(array[l], array[r]);
    recrev(array, l+1, r-1);
}

int main() {
    cout << "Enter size of the array: ";
    int n; cin >> n;
    cout << "Enter elements seperated with a space\n";
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    recrev(array, 0, n-1);
    cout << "Reversed array:\n";
    for (auto n: array) {
        cout << n << " ";
    }
    cout << endl;
}