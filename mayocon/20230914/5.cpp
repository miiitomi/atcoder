// https://atcoder.jp/contests/abc298/tasks/abc298_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int N, A, B, P, Q;
vector<vector<mint>> dp;
vector<vector<bool>> done;

mint rec(int i, int j) {
    if (done[i][j]) return dp[i][j];
    done[i][j] = true;
    for (int x = 1; x <= P; x++) {
        for (int y = 1; y <= Q; y++) {
            dp[i][j] = dp[i][j] + rec(min(N-1, i + x), min(N-1, j + y)) / (P*Q);
        }
    }
    return dp[i][j];
}

int main() {
    cin >> N >> A >> B >> P >> Q;
    dp.assign(N, vector<mint>(N, 0));
    done.assign(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        done[i][N-1] = true;
        dp[N-1][i] = 1;
        done[N-1][i] = true;
    }

    rec(A-1, B-1);
    cout << dp[A-1][B-1].val() << endl;
}
