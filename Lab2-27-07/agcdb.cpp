#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b) {
    if (b==0) return a;
    return solve(b, a%b);
}

int main(int argc, char* argv[]) {
    string inputPath;
    string outputPath;
    if(argc!=3) {
        cout << "USAGE: ./a.exe {input file} {output file}" << endl;
        return 0;
    } else {
        inputPath = argv[1];
        outputPath = argv[2];
    }
    int n;
    cout << "Enter number of pairs you want to input from the file\n";
    cin >> n;
    ifstream inputFile(inputPath);
    ofstream outputFile(outputPath);
    for (int i = 0; i < n; i++) {
        int a, b;
        inputFile >> a;
        inputFile >> b;
        int gcd_ab = solve(a, b);
        string res = "GCD of " + to_string(a) + " & " + to_string(b) + " is: " + to_string(gcd_ab);
        cout << res << endl;
        outputFile << res << endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}