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
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N);
    Fenwick<ll> f(N);
    ll all_inversion = 0;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
        all_inversion += f.query(P[i], N);
        f.add(P[i], 1);
    }
    Fenwick<ll> g(N);
    ll tmp = 0;
    for (int i = 0; i < K; i++) {
        tmp += g.query(P[i], N);
        g.add(P[i], 1);
    }
    mint p = ((mint)(N-K+1)).inv();
    mint q = ((mint)2).inv();
    mint ans = 0;
    for (int r = K; r <= N; r++) {
        int l = r - K;
        ans += p*(all_inversion - tmp + q * (mint)(K*(K-1)/2));
        tmp -= g.query(0, P[l]);
        g.add(P[l], -1);
        if (r < N) {
            tmp += g.query(P[r], N);
            g.add(P[r], 1);
        }
    }
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
