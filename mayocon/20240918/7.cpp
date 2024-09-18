// https://atcoder.jp/contests/abc346/tasks/abc346_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename X, typename M> struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = {INF, 0};  // TODO: Set initial value of data X.
    M M_init = 0;  // TODO: Set initial value of act M.

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
    }

    X X_operation(X a, X b) {
        // TODO: Set operation on X x X. (e.g., min, max, +)
        if (a.first < b.first) return a;
        else if (a.first > b.first) return b;
        else return {a.first, a.second+b.second};
    }

    M M_operation(M a, M b) {
        // TODO: Set operation on M x M.
        return a + b;
    }

    X X_M_operation(X x, M m) {
        // TODO: Set operation on X x M
        return {x.first+m, x.second};
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
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<vector<ll>> B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        B[A[i]].push_back(i);
    }
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> Q;
    for (auto &v : B) {
        for (int i = 0; i < (int)v.size(); i++) {
            vector<ll> w{0, v[i], v[i], N-1};
            if (i != 0) w[0] = v[i-1]+1;
            if (i != (int)v.size()-1) w[3] = v[i+1]-1;
            Q.push(w);
        }
    }
    LazySegmentTree<pair<ll,ll>, ll> lst(N);
    for (int i = 0; i < N; i++) lst.initialize(i, {0, 1});
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> R;
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        while (!Q.empty() && Q.top().front() == i) {
            vector<ll> w = Q.top();
            Q.pop();
            lst.update(w[2], w[3]+1, 1);
            R.push({w[1], w[2], w[3]});
        }
        pair<ll,ll> res = lst.query(i, N);
        ans += N - i - (res.first == 0)*res.second;
        while (!R.empty() && R.top().front() == i) {
            vector<ll> w = R.top();
            R.pop();
            lst.update(w[1], w[2]+1, -1);
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
