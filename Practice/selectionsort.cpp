#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int minInd = i;
        for (int j = i+1; j < n; j++) {
            if(arr[j] < arr[minInd]) {
                minInd = j;
            }
        }
        swap(arr[i], arr[minInd]);
    }
}

int main() {
    vector<int> arr = {5, 3, 10, 1, 4 ,2};
    selectionSort(arr, arr.size());
    for (auto a: arr) {
        cout << a << " ";
    }
    cout << endl;
}

// void selectionSort(vector<int>& arr, int n) {
//     for (int i = 0; i < n-1; i++) {
//         int minInd =i;
//         for (int j = i+1; j < n; j++) {
//             if(arr[j] < arr[minInd]) {
//                 minInd = j;
//             }
//         }
//         swap(arr[i], arr[minInd]);
//     }
// }
