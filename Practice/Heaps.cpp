#include <bits/stdc++.h>
using namespace std;


void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if(largest != i) {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if(right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if(i!=smallest) {
        swap(arr[smallest], arr[i]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(vector<int>& arr, int n){
    int ind = (n-1)/2;
    for (int i = ind; i >=0 ; i--) {
        minHeapify(arr, n, i);
    }
}

void buildMaxHeap(vector<int>& arr, int n) {
    int ind = (n-1)/2; // index of last non leaf node;
    for (int i = ind; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void printHeap(vector<int>& arr, int N) {
    cout << "Array representation of Heap is:\n";
    for (int i = 0; i < N; ++i) cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    // Binary Tree Representation
    // of input array
    //             1
    //           /    \
    //         3        5
    //       /  \     /  \
    //     4      6  13  10
    //    / \    / \
    //   9   8  15 17
    vector<int> arr = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

    int N = arr.size();

    // Function call
    buildMaxHeap(arr, N);
    printHeap(arr, N);
    buildMinHeap(arr, N);
    printHeap(arr, N);

    // Final Heap:
    //              17
    //            /    \
    //          15      13
    //         /  \     / \
    //        9     6  5   10
    //       / \   / \
    //      4   8 3   1

    return 0;
}