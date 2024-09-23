// https://atcoder.jp/contests/abc106/tasks/abc106_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> struct Fenwick {
    int n;
    vector<T> data;

    Fenwick(int _n) {
        n = _n + 1;
        data.assign(n, 0);
    }

    void add(int i, T x) {
        // Add x to a[i] (0-indexed).
        for (int idx = i + 1; idx < n; idx += (idx & -idx)) {
            data[idx] += x;
        }
    }

    T _sum(int i) {
        // compute sum of a[k] for k in [0, i)
        T ans = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            ans += data[idx];
        }
        return ans;
    }

    T query(int a, int b) {
        // compute sum of a[k] for k in [a, b)
        return _sum(b) - _sum(a);
    }
};

void solve() {
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<Fenwick<ll>> f(N, Fenwick<ll>(N));
    for (int i = 0; i < M; i++) {
        ll l, r;
        cin >> l >> r;
        l--; r--;
        f[l].add(r, 1);
    }
    while (Q--) {
        ll p, q, ans = 0;
        cin >> p >> q;
        p--; q--;
        for (ll i = p; i <= q; i++) {
            ans += f[i].query(i, q+1);
        }
        cout << ans << "\n";
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
