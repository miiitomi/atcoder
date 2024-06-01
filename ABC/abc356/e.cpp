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
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll M = 1 + *max_element(A.begin(), A.end());
    Fenwick<ll> F(M);
    for (int a : A) F.add(a, 1);

    ll ans = 0;
    for (ll x = 1; x < M; x++) {
        ll c = F.sum(x, x+1);
        if (c == 0) continue;
        if (c >= 2) ans += (c * (c-1))/2;
        ans += c*F.sum(x+1, min(2*x, M));
        for (ll y = 2*x; y < M; y += x) {
            ans += c*(y/x)*F.sum(y, min(y+x, M));
        }
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
