#include <bits/stdc++.h>
using namespace std;

int multiply(int x, int y) {
    if (x < 10 || y < 10) {
        return x * y;
    }
    int a = x / 10;
    int b = x % 10;
    int c = y / 10;
    int d = y % 10;
    int ac = multiply(a, c);
    int bd = multiply(b, d);
    int ad = multiply(a, d);
    int bc = multiply(b, c);
    return ac*100 + 10*ad + 10*bc + bd;
}

int main() {
    cout << "Enter two 2 digit numbers:\n";
    int a, b;
    cin >> a >> b;
    cout << multiply(a, b) << endl;
}