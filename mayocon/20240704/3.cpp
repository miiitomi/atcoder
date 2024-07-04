// https://atcoder.jp/contests/abc174/tasks/abc174_d
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
    ll N;
    cin >> N;
    Fenwick<ll> R(N), W(N);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == 'R') R.add(i, 1);
        else W.add(i, 1);
    }
    ll ans = min(R.sum(0, N), W.sum(0, N));
    for (int k = 1; k <= N-1; k++) {
        ll x = W.sum(0, k), y = R.sum(k, N);
        ans = min(ans, max(x, y));
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
