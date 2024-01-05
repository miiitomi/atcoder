// https://atcoder.jp/contests/abc058/tasks/abc058_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    for (int i = 0; i < S.size(); i++) {
        cout << S[i];
        if (i < T.size()) cout << T[i];
    }
    cout << endl;
}
