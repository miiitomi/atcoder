// https://atcoder.jp/contests/abc118/tasks/abc118_d
#include <bits/stdc++.h>
using namespace std;

vector<int> need{(int)1e+9, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];

    vector<string> dp(N+1, "");
    for (int i = 0; i < N; i++) {
        if (i != 0 && dp[i] == "") continue;
        for (int a : A) {
            if (i + need[a] > N || dp[i].size() + 1 < dp[i+need[a]].size()) continue;
            dp[i].push_back((char)(a + '0'));
            if (dp[i].size() > dp[i+need[a]].size() || dp[i] > dp[i+need[a]]) {
                dp[i+need[a]] = dp[i];
            }
            dp[i].pop_back();
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
