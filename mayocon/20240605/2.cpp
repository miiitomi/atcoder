// https://atcoder.jp/contests/abc279/tasks/abc279_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W;
    cin >> H >> W;
    swap(H, W);
    vector<string> S(H, string(W, '.')), T(H, string(W, '.'));
    for (int j = 0; j < W; j++) for (int i = 0; i < H; i++) cin >> S[i][j];
    for (int j = 0; j < W; j++) for (int i = 0; i < H; i++) cin >> T[i][j];

    multiset<string> SS, TT;
    for (string s : S) SS.insert(s);
    for (string t : T) TT.insert(t);

    if (SS == TT) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
