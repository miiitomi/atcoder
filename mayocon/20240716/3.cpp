// https://atcoder.jp/contests/abc088/tasks/abc088_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<vector<ll>> c(3, vector<ll>(3));
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> c[i][j];

    vector<ll> a(3), b(3);
    a[0] = 0;
    b[0] = c[0][0] - a[0];
    b[1] = c[0][1] - a[0];
    b[2] = c[0][2] - a[0];
    a[1] = c[1][0] - b[0];
    a[2] = c[2][0] - b[0];

    bool is_ok = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (c[i][j] != a[i]+b[j]) is_ok = false;
        }
    }

    if (is_ok) cout << "Yes\n";
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
