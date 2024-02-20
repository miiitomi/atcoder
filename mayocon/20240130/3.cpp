// https://atcoder.jp/contests/abc122/tasks/abc122_c
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
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    Fenwick<int> f(N);
    for (int i = 1; i < N; i++) {
        if (S[i-1] == 'A' && S[i] == 'C') f.add(i, 1);
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (S[l] == 'A') cout << f.sum(l, r+1) << "\n";
        else cout << f.sum(l+1, r+1) << "\n";
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
