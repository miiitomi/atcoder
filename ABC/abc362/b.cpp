#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool f(ll x1, ll y1, ll x2, ll y2) {
    return (x1*x2 + y1*y2 == 0);
}

void solve() {
    vector<ll> x(3), y(3);
    for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];

    bool is_true = false;
    if (f(x[1]-x[0], y[1]-y[0], x[2]-x[0], y[2]-y[0])) is_true = true;
    if (f(x[0]-x[1], y[0]-y[1], x[2]-x[1], y[2]-y[1])) is_true = true;
    if (f(x[0]-x[2], y[0]-y[2], x[1]-x[2], y[1]-y[2])) is_true = true;

    if (is_true) cout << "Yes\n";
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
