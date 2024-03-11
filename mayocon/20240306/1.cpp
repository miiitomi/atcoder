// https://atcoder.jp/contests/abc291/tasks/abc291_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    for (int i = 0; i < (int)S.size(); i++) {
        char c = S[i];
        if ('A' <= c && c <= 'Z') cout << i+1 << endl;
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
