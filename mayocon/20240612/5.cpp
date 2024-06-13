// https://atcoder.jp/contests/abc231/tasks/abc231_f
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
    vector<int> v;
    vector<pair<int,int>> P(N), Q;
    for (int i = 0; i < N; i++) cin >> P[i].first;
    for (int i = 0; i < N; i++) {
        cin >> P[i].second;
        v.push_back(P[i].first);
        v.push_back(P[i].second);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) {
        P[i].first = distance(v.begin(), lower_bound(v.begin(), v.end(), P[i].first));
        P[i].second = distance(v.begin(), lower_bound(v.begin(), v.end(), P[i].second));
    }
    sort(P.begin(), P.end());
    Q = P;
    reverse(Q.begin(), Q.end());

    Fenwick<ll> f(v.size());

    ll ans = 0;
    for (pair<int,int> &p : P) {
        while (!Q.empty() && Q.back().first <= p.first) {
            f.add(Q.back().second, 1);
            Q.pop_back();
        }
        ans += f.sum(p.second, (int)v.size());
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
