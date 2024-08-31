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
    vector<ll> A(N), B(N);
    set<int> b_notone_idx;
    Fenwick<ll> SA(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        SA.add(i, A[i]);
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        if (B[i] != 1) b_notone_idx.insert(i);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        ll t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            l--;
            SA.add(l, r - A[l]);
            A[l] = r;
        } else if (t == 2) {
            l--;
            if (b_notone_idx.contains(l)) b_notone_idx.erase(l);
            B[l] = r;
            if (B[l] != 1) b_notone_idx.insert(l);
        } else {
            l--;
            ll v = 0;
            while (l < r) {
                auto iter = b_notone_idx.lower_bound(l);
                int m = r;
                if (iter != b_notone_idx.end()) m = min(m, *iter);

                if (l < m) {
                    v += SA.query(l, m);
                    l = m;
                }

                if (l == r) break;
                v = max(v + A[l], B[l]*v);
                l++;
            }
            cout << v << "\n";
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
