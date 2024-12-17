// https://atcoder.jp/contests/abc179/tasks/abc179_d
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
    vector<pair<ll,ll>> P(K);
    for (int k = 0; k < K; k++) {
        cin >> P[k].first >> P[k].second;
    }
    sort(P.begin(), P.end());
    Fenwick<mint> f(N);
    f.add(0, (mint)1);
    for (int x = 1; x < N; x++) {
        for (auto &p : P) {
            int r = x - p.first, l = max(0LL, x - p.second);
            if (r < 0) break;
            f.add(x, f.query(l, r+1));
        }
    }
    mint ans = f.query(N-1, N);
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
