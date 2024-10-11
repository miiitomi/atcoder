// https://atcoder.jp/contests/abc209/tasks/abc209_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> struct CumulativeSum {
    int N;
    vector<T> data;

    CumulativeSum(vector<T> &A) {
        N = A.size();
        data.assign(N+1, 0);
        for (int i = 0; i < N; i++) data[i+1] = data[i] + A[i];
    }

    T query(int l, int r) {
        // Return Sum of [l, r)
        return data[r]-data[l];
    }
};

void solve() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    vector<vector<mint>> dp(N, vector<mint>(N, 0));
    dp[0][0] = 1;
    for (int i = 1; i < N; i++) {
        CumulativeSum<mint> cs(dp[i-1]);
        for (int j = 0; j <= i; j++) {
            if (H[i-1] == H[i]) dp[i][j] = cs.query(0, N);
            else if (H[i-1] < H[i]) dp[i][j] = cs.query(j, N);
            else dp[i][j] = cs.query(0, j);
        }
    }
    CumulativeSum<mint> cs(dp.back());
    cout << cs.query(0, N).val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
