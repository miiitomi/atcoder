// https://atcoder.jp/contests/abc124/tasks/abc124_d
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
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<pair<char,int>> V;
    for (char c : S) {
        if (!V.empty() && V.back().first==c) V.back().second++;
        else V.push_back({c, 1});
    }
    N = V.size();
    Fenwick<ll> f(N);
    for (int i = 0; i < N; i++) f.add(i, V[i].second);
    ll ans = -INF;
    for (int i = 0; i < N; i++) {
        int l, r;
        if (V[i].first == '0') {
            l = max(0, i-1);
            r = min(N, i + 2*K);
        } else {
            l = i;
            r = min(N, i + 2*K + 1);
        }
        ans = max(ans, f.query(l, r));
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
