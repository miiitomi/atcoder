// https://atcoder.jp/contests/abc361/tasks/abc361_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool is_crossing(ll l1, ll r1, ll l2, ll r2) {
    if (r1 <= l2 || r2 <= l1) return false;
    return true;
}

void solve() {
    vector<ll> V(6), W(6);
    for (int i = 0; i < 6; i++) cin >> V[i];
    for (int i = 0; i < 6; i++) cin >> W[i];

    bool pos = true;
    for (int i = 0; i < 3; i++) {
        pos = (pos && is_crossing(min(V[i], V[i+3]), max(V[i], V[i+3]), min(W[i], W[i+3]), max(W[i], W[i+3])));
    }
    if (pos) cout << "Yes\n";
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
