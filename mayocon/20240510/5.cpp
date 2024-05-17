// https://atcoder.jp/contests/abc157/tasks/abc157_e
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
    string S;
    cin >> N >> S;
    vector<Fenwick<int>> F(26, Fenwick<int>(N));
    for (int i = 0; i < N; i++) {
        int k = S[i] - 'a';
        F[k].add(i, 1);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            char c;
            cin >> i >> c;
            i--;
            int k = S[i] - 'a';
            F[k].add(i, -1);
            S[i] = c;
            k = S[i] - 'a';
            F[k].add(i, 1);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            int ans = 0;
            for (int k = 0; k < 26; k++) {
                ans += ((bool)F[k].sum(l, r));
            }
            cout << ans << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
