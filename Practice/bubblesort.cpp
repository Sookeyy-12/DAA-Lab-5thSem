#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if( arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    vector<int> arr = {5, 1, 2, 10, 4, 3};
    bubbleSort(arr, arr.size());
    for (auto a: arr) {
        cout << a << " ";
    }
    cout << endl;
}


// for (int i = 0; i < n-1; i++) {
//         for (int j = 0; j < n-i-1; j++) {
//             if(arr[j] > arr[j+1]) {
//                 swap(arr[j], arr[j+1]);
//             }
//         }
//     }