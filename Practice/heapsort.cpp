#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right<n && arr[right] > arr[largest]) {
        largest = right;
    }
    if(largest!=i) {
        swap(arr[i], arr[largest]);
    }
}

void heapSort(vector<int>& arr, int n) {
    // build heap
    for(int i = (n-2)/2; i>=0; i--) {
        heapify(arr, n, i);
    }
    // sort
    for (int i = n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// A utility function to print array of size n
void printArray(vector<int>& arr, int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver's code
int main()
{
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int N = arr.size();

    // Function call
    heapSort(arr, N);

    cout << "Sorted array is \n";
    printArray(arr, N);
}

// void heapify(vector<int>& arr, int n, int i) {
//     int largest = i;
//     int left = 2*i+1;
//     int right = 2*i+2;
//     if(left < n && arr[left] > arr[largest]) {
//         largest = left;
//     }
//     if(right < n && arr[right] > arr[largest]) {
//         largest = right;
//     }
//     if(largest!=i) {
//         swap(arr[largest], arr[i]);
//     }
// }

// void heapSort(vector<int>& arr, int n) {
//     // create maxheap
//     for (int i = (n-1)/2; i>=0; i--) {
//         heapify(arr, n, i);
//     }
//     for (int i = n-1; i > 0; i--) {
//         swap(arr[0], arr[i]);
//         heapify(arr, i, 0);
//     }
// }