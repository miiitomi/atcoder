// https://atcoder.jp/contests/abc247/tasks/abc247_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S, T(4, '0');
    cin >> S;
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
