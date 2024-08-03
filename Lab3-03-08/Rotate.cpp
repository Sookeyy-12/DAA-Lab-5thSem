#include <bits/stdc++.h>
using namespace std;

void rotateRight(vector<int>& array, int k) {
    for (int i = k-1; i>0; i--) {
        swap(array[i], array[i-1]);
    }
}
void rotateLeft(vector<int>& array, int k) {
    for (int i = 0; i<k-1; i++) {
        swap(array[i], array[i+1]);
    }
}

int main() {
    cout << "Enter size of the array: ";
    int n; cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of the array (seperated by space)\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter R to shift right and L to shift left\n";
    char choice; cin >> choice;
    int k;
    cout << "Enter by how many positions you want to rotate: ";
    cin >> k;
    switch (choice)
    {
    case 'R':
        rotateRight(arr, k);
        break;
    case 'L':
        rotateLeft(arr, k);
        break;
    default:
        break;
    }
    cout << "Rotated Array:\n";
    for (auto n: arr) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}