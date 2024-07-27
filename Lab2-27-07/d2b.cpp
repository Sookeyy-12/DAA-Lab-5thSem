// decimal to binary
#include <bits/stdc++.h>
using namespace std;

void getBinary(int num, string& bin) {
    if(num==0) return;
    bin += to_string(num&1);
    getBinary(num>>1, bin);
}

void solve(vector<int>& array) {
    ofstream outputFile("output1.dat");
    for (auto num: array) {
        string binary = "";
        getBinary(num, binary);
        outputFile << binary << endl;
    }
    outputFile.close();
}

int main() {
    int n; 
    cout << "How many number do you want to read from the file?\n";
    cin >> n;
    ifstream inputFile("input1.dat");
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        inputFile >> array[i];
    }
    inputFile.close();
    solve(array);
    return 0;
}