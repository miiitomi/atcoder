#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.length();
    int count = 0;

    for (int i = 0; i < n-3; i++) {
        bool ans = true;
        if (S.at(i) != 'Z') {
            ans = false;
        }
        if (S.at(i+1) != 'O') {
            ans = false;
        }
        if (S.at(i+2) != 'N') {
            ans = false;
        }
        if (S.at(i+3) != 'e') {
            ans = false;
        }
        if (ans) {
            count++;
        }
    }
    cout << count << endl;
}