// https://atcoder.jp/contests/abc306/tasks/abc306_f
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
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> A(N, vector<ll>(M));
    vector<ll> v;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        cin >> A[i][j];
        v.push_back(A[i][j]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        sort(A[i].begin(), A[i].end());
        for (int j = 0; j < M; j++) {
            A[i][j] = distance(v.begin(), lower_bound(v.begin(), v.end(), A[i][j]));
        }
    }

    Fenwick<ll> f(N*M);
    ll ans = 0;
    for (int i = N-2; i >= 0; i--) {
        for (ll a : A[i+1]) f.add(a, 1);
        for (int j = 0; j < M; j++) {
            ans += (j+1) * (N-1-i) + f.sum(A[i][j]);
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
