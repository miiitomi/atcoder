// https://atcoder.jp/contests/abc262/tasks/abc262_c
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
    Fenwick<int> f(N+1);
    vector<set<int>> S(N+1);
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        if (i == a) {
            ans += f.sum(0, a);
            f.add(a, 1);
        } else if (i > a) {
            if (S[i].count(a)) ans++;
        } else if (i < a) {
            S[a].insert(i);
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
