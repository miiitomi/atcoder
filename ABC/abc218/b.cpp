#include <bits/stdc++.h>
using namespace std;

int main() {
    string S = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 26; i++) {
        int x;
        cin >> x;
        x--;
        cout << S[x];
    }
    cout << endl;
}
