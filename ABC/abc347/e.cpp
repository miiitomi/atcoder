#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
struct Fenwick {
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

    T sum(int i) {
        // compute sum of a[i] with i in [0, i)
        T ans = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            ans += data[idx];
        }
        return ans;
    }

    T sum(int a, int b) {
        // compute sum of a[i] with i in [a, b)
        return sum(b) - sum(a);
    }
};

void solve() {
    ll N, Q;
    cin >> N >> Q;
    vector<bool> S(N+1, false);
    Fenwick<ll> f(Q+2);
    vector<ll> in(N+1, -1), ans(N+1, 0);
    for (int q = 1; q <= Q; q++) {
        ll x;
        cin >> x;
        if (!S[x]) {
            S[x] = true;
            in[x] = q;
            f.add(q, f.sum(q-1, q) + 1);
        } else {
            S[x] = false;
            ans[x] += f.sum(in[x], q);
            f.add(q, f.sum(q-1, q) - 1);
        }
    }
    for (int x = 1; x <= N; x++) {
        if (S[x]) ans[x] += f.sum(in[x], Q+1);
        cout << ans[x] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
