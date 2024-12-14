// https://atcoder.jp/contests/abc245/tasks/abc245_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    d++;
    if (d == 60) {
        d = 0;
        c++;
    }

    if (a < c || (a == c && b < d)) cout << "Takahashi\n";
    else cout << "Aoki\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
