#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    vector<int> arr = { 12, 11, 13, 5, 6 };
    int n = arr.size();

    insertionSort(arr, n);
    for (auto a: arr) cout << a << " ";
    cout << endl;

    return 0;
}


// void insertionSort(vector<int>& arr, int n) {
//     for(int i = 1; i < n; i++) {
//         int key = arr[i];
//         int j = i-1;
//         while(j>=0 && key < arr[j]) {
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1]=key;
//     }
// }