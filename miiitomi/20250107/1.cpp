// https://atcoder.jp/contests/abc077/tasks/abc077_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<string> S(2);
    for (string &s : S) cin >> s;
    vector<string> T = S;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            T[1-i][2-j] = S[i][j];
        }
    }
    if (S == T) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
