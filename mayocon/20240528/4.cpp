// https://atcoder.jp/contests/abc334/tasks/abc334_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K;
vector<ll> B;

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
        if (i <= 0) return 0;
        T ans = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            ans += data[idx];
        }
        return ans;
    }

    T sum(int a, int b) {
        // compute sum of a[i] with i in [a, b)
        if (b <= a) return 0;
        return sum(b) - sum(a);
    }
};

void odd() {
    Fenwick<ll> e(B.size()), o(B.size());
    for (int i = 1; i < (int)B.size(); i++) {
        if (i % 2) o.add(i, B[i]-B[i-1]);
        else e.add(i, B[i]-B[i-1]);
    }
    ll ans = 1e+18;
    for (int i = 0; i < (int)B.size(); i+=2) {
       ll tmp = o.sum(0, i) + e.sum(i+1, B.size());
       ans = min(ans, tmp);
    }
    cout << ans << "\n";
}

void even() {
    ll ans = 0;
    for (int i = 0; i+1 < (int)B.size(); i += 2) {
        ans += B[i+1]-B[i];
    }
    cout << ans << endl;
}

void solve() {
    cin >> N >> K;
    vector<bool> c(N+1, true);
    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        c[a] = false;
    }
    for (int i = 1; i <= N; i++) {
        B.push_back(i);
        if (c[i]) B.push_back(i);
    }
    if ((2*N-K)%2) odd();
    else even();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
