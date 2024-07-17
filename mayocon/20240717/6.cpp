// https://atcoder.jp/contests/abc334/tasks/abc334_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const double INF = 2e+18;

double d(pair<ll,ll> &p, pair<ll,ll> &q) {
    return sqrt((p.first-q.first)*(p.first-q.first) + (p.second-q.second)*(p.second-q.second)+0.0);
}

template<typename X, typename M> struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = INF; // TODO: Set initial value of data X.
    M M_init = 0.0; // TODO: Set initial value of act M.

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
    }

    X X_operation(X a, X b) {
        // TODO: Set operation on X x X. (e.g., min, max, +)
        return min(a, b);
    }

    M M_operation(M a, M b) {
        // TODO: Set operation on M x M.
        return a+b;
    }

    X X_M_operation(X x, M m) {
        // TODO: Set operation on X x M
        return x + m;
    }

    void initialize(int i, X x) {
        i = n - 1 + i;
        data[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = X_operation(data[i*2 + 1], data[i*2 + 2]);
        }
    }

    void eval(int k) {
        if (lazy[k] == M_init) return;
        if (k < n - 1) {
            lazy[k * 2 + 1] = M_operation(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = M_operation(lazy[k * 2 + 2], lazy[k]);
        }
        data[k] = X_M_operation(data[k], lazy[k]);
        lazy[k] = M_init;
    }

    void _update(int a, int b, M m, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {
            lazy[k] = M_operation(lazy[k], m);
            eval(k);
        } else if (a < r && l < b) {
            _update(a, b, m, k * 2 + 1, l, (l + r) / 2);
            _update(a, b, m, k * 2 + 2, (l + r) / 2, r);
            data[k] = X_operation(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }

    // Update data[i] with i in [a, b) by multiplying m in M.
    void update(int a, int b, M m) {
        _update(a, b, m, 0, 0, n);
    }

    X _sub_query(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {
            return X_init;
        } else if (a <= l && r <= b) {
            return data[k];
        } else {
            X vl = _sub_query(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = _sub_query(a, b, k * 2 + 2, (l + r) / 2, r);
            return X_operation(vl, vr);
        }
    }

    // Return the answer in [a, b)
    X query(int a, int b) {
        return _sub_query(a, b, 0, 0, n);
    }
};

void solve() {
    ll N, K;
    cin >> N >> K;
    LazySegmentTree<double, double> lst(N);
    for (int i = 0; i < N; i++) lst.initialize(i, 0.0);
    pair<ll,ll> s;
    cin >> s.first >> s.second;
    vector<pair<ll,ll>> P(N);
    for (int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;
    lst.update(0, 1, d(s, P[0]));
    for (int i = 1; i < N; i++) {
        double r = lst.query(max(i-K, 0LL), i) + d(P[i-1], s) + d(s, P[i]);
        lst.update(i, i+1, r);
        lst.update(0, i, d(P[i-1], P[i]));
    }

    double ans = INF;
    for (int k = 1; k <= K; k++) {
        ans = min(ans, lst.query(N-k, N-k+1) + d(P.back(), s));
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
