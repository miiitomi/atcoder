// https://atcoder.jp/contests/abc280/tasks/abc280_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S, T;
    cin >> S >> T;
    vector<bool> a(S.size(), false), b(S.size(), false);
    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] != T[i]) break;
        a[i] = true;
    }
    for (int i = 0; i < (int)S.size(); i++) {
        if (S[S.size()-1-i] != T[T.size()-1-i]) break;
        b[S.size()-1-i] = true;
    }

    for (int i = 0; i < (int)T.size(); i++) {
        if ((i == 0 || a[i-1]) && (i == (int)T.size()-1 || b[i])) {
            cout << i+1 << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
