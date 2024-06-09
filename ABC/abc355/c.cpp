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
    int N, T;
    cin >> N >> T;
    vector<Fenwick<int>> R(N, Fenwick<int>(N)), C(N, Fenwick<int>(N));
    Fenwick<int> X(N), Y(N);

    for (int t = 1; t <= T; t++) {
        int a;
        cin >> a;
        a--;
        int r = a/N, c = a%N;
        R[r].add(c, 1);
        C[c].add(r, 1);
        if (r == c) X.add(r, 1);
        if (r == N-1-c) Y.add(r, 1);
        if (R[r].sum(N) == N || C[c].sum(N) == N || (r==c && X.sum(N) == N) || (r == N-1-c && Y.sum(N) == N)) {
            cout << t << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
