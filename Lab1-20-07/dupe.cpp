#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& numbers) {
    cout << "Content of the array: " << endl;
    for (auto n: numbers) cout << n << " ";
    cout << endl;
    unordered_map<int, int> mp;
    for (auto n: numbers) {
        mp[n]++;
    }
    int freqel = 0;
    int freq = 0;
    int cnt =0 ;
    for (auto m: mp) {
        if (m.second > 1) {
            cnt++;
        }
        if (m.second > freq) {
            freqel = m.first;
            freq = m.second;
        }
    }
    cout << "Total number of repeating elements: " << cnt << endl;
    cout << "Most Frequent element: " << freqel << endl;
}

int main() {
    int n; 
    cout << "Enter how many numbers you want to read from file? \n";
    cin >> n;
    ifstream inputFile("q5input.txt");
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        inputFile >> numbers[i];
    }
    inputFile.close();
    solve(numbers);
    return 0;
}