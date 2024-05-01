#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

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
    int N;
    cin >> N;
    vector<ll> A(N), v;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        v.push_back(A[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) A[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), A[i]));
    int M = v.size() + 1;
    ll ans = 0;
    Fenwick<ll> f(M);
    for (int i = 0; i < N; i++) {
        ll a = v[A[i]];
        ans += a * f.sum(0, A[i]);
        f.add(A[i], 1);
    }
    Fenwick<ll> g(M);
    for (int i = N-1; i >= 0; i--) {
        ll a = v[A[i]];
        ans -= a * g.sum(A[i]+1, M-1);
        g.add(A[i], 1);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
