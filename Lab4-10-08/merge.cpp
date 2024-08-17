#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> LeftArr(n1), RightArr(n2);
    for (int i = 0; i < n1; i++) {
        LeftArr[i] = array[left+i];
    }
    for (int i = 0; i < n2; i++) {
        RightArr[i] = array[mid+i+1]; 
    }
    int i = 0, j =0;
    int k = left;
    while (i < n1 && j < n2) {
        if(LeftArr[i] < RightArr[j]){
            array[k] = LeftArr[i];
            i++;
        } else {
            array[k] = RightArr[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        array[k] = LeftArr[i];i++;k++;
    }
    while(j < n2) {
        array[k] = RightArr[j];j++;k++;
    }
}

void mergeSort(vector<int>& array, int left, int right) {
    if(left>=right) return;
    int mid = left + (right-left)/2;
    mergeSort(array, left, mid);
    mergeSort(array, mid+1, right);
    merge(array, left, mid, right);
}

int main() {
    cout << "Enter the number of elements: ";
    int n; cin >> n;
    vector<int> array(n);
    cout << "Enter Elements of the array:\n";
    for (auto &a: array) cin >> a;
    mergeSort(array, 0, n-1);
    cout << "Sorted array:\n";
    for (auto a: array) {
        cout << a << " ";
    }
    cout << endl;
}