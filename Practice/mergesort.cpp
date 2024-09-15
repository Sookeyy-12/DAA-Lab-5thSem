#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int lo, int mid, int hi) {
    int n1 = mid-lo+1;
    int n2 = hi-mid;
    vector<int> leftArr(arr.begin(), arr.begin()+mid+1);
    vector<int> rightArr(arr.begin()+mid+1, arr.end());
    int i = 0, j = 0;
    int k = lo;
    while(i<n1 && j < n2) {
        if(leftArr[i] < rightArr[j]) {
            arr[k] = leftArr[i];
            i++;k++;
        } else {
            arr[k] = rightArr[j];
            k++;j++;
        }
    }
    while(i<n1) {
        arr[k] = leftArr[i];
        i++;k++;
    } 
    while(j<n2) {
        arr[k] = rightArr[j];
        j++;k++;
    } 
}

void mergeSort(vector<int>& arr, int lo, int hi) {
    if(lo>=hi) {
        return;
    }
    int mid = lo + (hi-lo)/2;
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid+1, hi);
    merge(arr, lo, mid, hi);
}

int main()
{
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    cout << "Given vector is \n";
    for (auto a: arr) cout << a << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted vector is \n";
    for (auto a: arr) cout << a << " ";
    cout << endl;
    return 0;
}