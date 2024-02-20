// https://atcoder.jp/contests/abc118/tasks/abc118_d
#include <bits/stdc++.h>
using namespace std;

vector<int> need{0,2,5,5,4,5,6,3,7,6};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    vector<int> dp(N+1, -1e+9);
    vector<pair<int,int>> back(N+1, make_pair(-1, -1));
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] < 0) continue;
        for (int a : A) {
            if (i+need[a] <= N) dp[i+need[a]] = max(dp[i+need[a]], dp[i] + 1);
        }
    }
    string ans = "";
    int i = N;
    while (i > 0) {
        for (int a : A) {
            if (i - need[a] >= 0 && dp[i - need[a]] == dp[i] - 1) {
                ans.push_back(a + '0');
                i -= need[a];
                break;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
