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
    ll N, T;
    cin >> N >> T;
    string S;
    cin >> S;
    vector<ll> X(N), v, w(N);
    for (int i = 0; i < N; i++) {
        w[i] = i;
        cin >> X[i];
        if (S[i] == '1') v.push_back(X[i] + T);
        else v.push_back(X[i] - T);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(w.begin(), w.end(), [&](const int l, const int r) {return X[l] < X[r];});
    reverse(w.begin(), w.end());

    Fenwick<ll> f((int)v.size());
    ll ans = 0;
    for (int i : w) {
        if (S[i] == '0') {
            ll x = X[i] - T;
            int j = distance(v.begin(), lower_bound(v.begin(), v.end(), x));
            f.add(j, 1);
        } else {
            ll x = X[i] + T;
            int j = distance(v.begin(), lower_bound(v.begin(), v.end(), x));
            ans += f.sum(0, j+1);
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
