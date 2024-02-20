// https://atcoder.jp/contests/abc110/tasks/abc110_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S, T;
    cin >> S >> T;
    int N = S.size();
    vector<set<int>> st(26);
    for (int i = 0; i < N; i++) st[S[i] - 'a'].insert(i);
    for (int i = 0; i < N; i++) {
        int d;
        for (int c = 0; c < 26; c++) if (st[c].count(i)) d = c;
        if (d != (T[i] - 'a')) {
            swap(st[d], st[(int)(T[i] - 'a')]);
        }
    }
    for (int c = 0; c < 26; c++) {
        for (int i : st[c]) S[i] = 'a' + c; 
    }
    if (S == T) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
