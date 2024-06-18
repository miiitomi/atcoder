// https://atcoder.jp/contests/abc178/tasks/abc178_d
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint1000000007;

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
    int S;
    cin >> S;
    vector<Fenwick<mint>> dp(1 + (S+2)/3, Fenwick<mint>(S+1));
    dp[0].add(0, 1);
    mint ans = 0;
    for (int i = 1; i < (int)dp.size(); i++) {
        for (int j = 3; j <= S; j++) {
            dp[i].add(j, dp[i-1].sum(0, j-2));
        }
        ans += dp[i].sum(S, S+1);
    }
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
