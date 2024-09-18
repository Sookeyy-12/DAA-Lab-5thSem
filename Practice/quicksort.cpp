#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int lo, int hi) {
    int piv = arr[hi];
    int i = lo-1;
    for (int j = lo; j < hi; j++) {
        if(arr[j] < piv) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    i++;
    swap(arr[i], arr[hi]);
    return i;
}

void quickSort(vector<int>& arr, int lo, int hi) {
    if(lo<hi) {
        int pivInd = partition(arr, lo, hi);
        quickSort(arr, lo, pivInd-1);
        quickSort(arr, pivInd+1, hi);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    cout << "Sorted Array\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}


// int partition(vector<int>& arr, int lo, int hi) {
//     int piv = arr[hi];
//     int i = lo-1;
//     for (int j = lo; j <=hi; j++) {
//         if(arr[j] < piv) {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     i++;
//     swap(arr[i], arr[hi]);
//     return i;
// }

// void quickSort(vector<int>& arr, int lo, int hi) {
//     if(lo<hi) {
//         int pivInd = partition(arr, lo, hi);
//         quickSort(arr, lo, pivInd-1);
//         quickSort(arr, pivInd+1, hi);
//     }
// }
