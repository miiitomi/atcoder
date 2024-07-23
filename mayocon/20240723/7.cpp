// https://atcoder.jp/contests/abc243/tasks/abc243_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll sqrt_lower(ll x) {
    ll left = 0, right = ((ll)3e+9) + 2;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        if (m*m > x) right = m;
        else left = m;
    }
    return left;
}

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
    ll M = (ll)2e+5;
    Fenwick<ll> f(M+1);
    f.add(1, 1);
    for (ll x = 2; x <= M; x++) f.add(x, f.query(1, sqrt_lower(x)+1));

    int T;
    cin >> T;
    while (T--) {
        ll X;
        cin >> X;
        ll x = sqrt_lower(X);
        ll ans = 0;
        if (x <= M) {
            ans = f.query(1, x+1);
        } else {
            ll Y = sqrt_lower(x);
            for (ll y = 1; y <= Y; y++) {
                ans += (x - y*y + 1) * f.query(y, y+1);
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    solve();
}
