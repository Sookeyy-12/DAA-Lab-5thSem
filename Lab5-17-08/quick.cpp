#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i+1], array[high]);
    return i+1;
}

void quickSort(vector<int>& array, int low, int high) {
    if (low < high) {
        int partition_index = partition(array, low, high);
        quickSort(array, low, partition_index-1);
        quickSort(array, partition_index+1, high);
    }
}

int main() {
    cout << "Enter number of elements in array: ";
    int n; cin >> n;
    cout << "Enter the elements of the array: ";
    vector<int> array(n);
    for (auto &a: array) cin >> a;
    quickSort(array, 0, n-1);
    cout << "Sorted Array:\n";
    for (auto a: array) cout << a << " ";
    cout << endl;
}