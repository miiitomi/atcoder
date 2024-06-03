// https://atcoder.jp/contests/abc270/tasks/abc270_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    for (int i = 0; i < K; i++) cin >> A[i];

    vector<int> dp(N+1, 0);
    for (int x = 1; x <= N; x++) {
        for (int a : A) {
            if (x - a < 0) continue;
            dp[x] = max(dp[x], a + (x - a - dp[x-a]));
        }
    }
    cout << dp[N] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
