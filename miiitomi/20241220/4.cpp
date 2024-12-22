// https://atcoder.jp/contests/abc261/tasks/abc261_f
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
    ll N;
    cin >> N;
    vector<ll> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        C[i]--;
    }
    ll ans = 0;
    Fenwick<ll> f(N);
    vector<vector<ll>> X(N);
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        x--;
        ans += f.query(x+1, N);
        f.add(x, 1);
        X[C[i]].push_back(x);
    }
    for (ll c = 0; c < N; c++) {
        vector<ll> W;
        for (ll x : X[c]) W.push_back(x);
        sort(W.begin(), W.end());
        W.erase(unique(W.begin(), W.end()), W.end());
        ll M = W.size();
        for (ll &x : X[c]) x = distance(W.begin(), lower_bound(W.begin(), W.end(), x));
        Fenwick<ll> g(M);
        for (ll x : X[c]) {
            ans -= g.query(x+1, M);
            g.add(x, 1);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
