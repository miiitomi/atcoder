// https://atcoder.jp/contests/abc078/tasks/abc078_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    char X, Y;
    cin >> X >> Y;
    if (X < Y) cout << "<\n";
    else if (X == Y) cout << "=\n";
    else cout << ">\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
