// https://atcoder.jp/contests/abc263/tasks/abc263_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

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
    vector<int> A(N-1);
    for (int i = 0; i < N-1; i++) cin >> A[i];
    Fenwick<mint> ft(N);
    for (int i = N-2; i >= 0; i--) {
        mint tmp = A[i]+1;
        tmp += ft.sum(i+1, i+A[i]+1);
        tmp /= A[i];
        ft.add(i, tmp);
    }
    mint ans = ft.sum(0, 1);
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
