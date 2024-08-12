// https://atcoder.jp/contests/abc181/tasks/abc181_e
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
    ll N, M;
    cin >> N >> M;
    vector<ll> H(N), W(M);
    for (int i = 0; i < N; i++) cin >> H[i];
    for (int i = 0; i < M; i++) cin >> W[i];
    sort(H.begin(), H.end());
    Fenwick<ll> left(N), right(N);
    for (int i = 1; i < N; i += 2) {
        left.add(i, H[i]-H[i-1]);
    }
    for (int i = N-2; i >= 0; i -= 2) {
        right.add(i, H[i+1]-H[i]);
    }
    ll ans = INF;
    for (ll w : W) {
        auto iter = lower_bound(H.begin(), H.end(), w);
        if (iter == H.begin()) ans = min(ans, right.query(1, N) + abs(w - H[0]));
        else if (iter == H.end()) ans = min(ans, left.query(0, N-1) + abs(w - H.back()));
        else {
            int i = distance(H.begin(), iter);
            if (i % 2 == 0) ans = min(ans, left.query(0, i) + abs(w - H[i]) + right.query(i+1, N));
            else ans = min(ans, left.query(0, i-1) + abs(w - H[i-1]) + right.query(i, N));
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
