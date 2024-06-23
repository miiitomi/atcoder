// https://atcoder.jp/contests/abc247/tasks/abc247_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    string T = "0000";
    for (int i = 0; i < 3; i++) if (S[i] == '1') T[i+1] = '1';
    cout << T << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
