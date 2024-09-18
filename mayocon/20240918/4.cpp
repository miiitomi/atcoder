// https://atcoder.jp/contests/abc217/tasks/abc217_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll L, Q;
    cin >> L >> Q;
    set<ll> S;
    S.insert(0);
    S.insert(L);

    while (Q--) {
        ll c, x;
        cin >> c >> x;
        if (c == 1) {
            S.insert(x);
        } else {
            auto iter = S.lower_bound(x+1);
            ll r = *iter;
            iter--;
            ll l = *iter;
            cout << r-l << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
