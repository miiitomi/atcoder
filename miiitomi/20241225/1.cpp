// https://atcoder.jp/contests/abc274/tasks/abc274_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int a, b;
    cin >> a >> b;
    cout << b/(a+0.0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(3);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
