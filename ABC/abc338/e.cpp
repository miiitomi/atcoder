#include <bits/stdc++.h>
using namespace std;

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
    vector<pair<int,int>> V(N);
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (v < u) swap(u, v);
        V[i] = make_pair(u, v);
    }
    sort(V.begin(), V.end());

    Fenwick<int> f(2*N);
    for (pair<int,int> &p : V) {
        if (f.sum(p.first, p.second)) {
            cout << "Yes" << endl;
            return;
        }
        f.add(p.second, 1);
    }
    cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
