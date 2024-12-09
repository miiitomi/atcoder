// https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int m1, d1, m2, d2;
    cin >> m1 >> d1 >> m2 >> d2;
    if (m1 == m2) cout << 0 << endl;
    else cout << 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
