// https://atcoder.jp/contests/abc253/tasks/abc253_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

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
    int N, M, K;
    cin >> N >> M >> K;
    vector<Fenwick<mint>> dp(N, Fenwick<mint>(M));
    for (int j = 0; j < M; j++) dp[0].add(j, 1);

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (K == 0) dp[i].add(j, dp[i-1].sum(0, M));
            else {
                if (j-K >= 0) dp[i].add(j, dp[i-1].sum(0, j-K+1));
                if (j+K <= M-1) dp[i].add(j, dp[i-1].sum(j+K, M));
            }
        }
    }
    mint ans = dp[N-1].sum(0, M);
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
