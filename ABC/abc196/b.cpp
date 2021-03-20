#include <bits/stdc++.h>
using namespace std;

int main() {
    string X;
    cin >> X;
    string A = "";

    for (char x : X) {
        if (x == '.') {
            break;
        }
        A = A + x;
    }
    cout << A << endl;
}